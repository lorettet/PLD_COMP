#include "ASMWriter_x86.h"
#include <sstream>
#include <iostream>

ASMWriter_x86::ASMWriter_x86(string name): ASMWriter(name)
{
}

void ASMWriter_x86::addInstrMov(string src, string dest, uint size)
{
  switch (size) {
    case 4:
      addInstr("movl "+src+", "+dest);
      break;
    case 8:
      addInstr("movq "+src+", "+dest);
      break;
  }

}

void ASMWriter_x86::addInstrAdd(string src, string dest, uint size)
{
  switch (size) {
    case 4:
      addInstr("addl "+src+", "+dest);
      break;
    case 8:
      addInstr("addq "+src+", "+dest);
      break;
  }

}

void ASMWriter_x86::addInstrSub(string src, string dest, uint size)
{
  switch (size) {
    case 4:
      addInstr("subl "+src+", "+dest);
      break;
    case 8:
      addInstr("subq "+src+", "+dest);
      break;
  }

}

void ASMWriter_x86::addInstrMult(string src)
{
      addInstr("imul "+src);
}

void ASMWriter_x86::addInstrDiv(string src)
{
	  addInstr("cltd");
    addInstr("idivl "+src);
}

void ASMWriter_x86::addInstrCall(string label)
{
	  addInstr("call "+label);
}

void ASMWriter_x86::addInstrNeg(string src)
{
	addInstr("neg "+src);
}

// void ASMWriter_x86::addInstrNot(string src)
// {
// 	//addInstr("neg "+src);
// }

void ASMWriter_x86::addInstrJmp(string label)
{
  addInstr("jmp "+label);
}

void ASMWriter_x86::addInstrJmpIfEqual(string label)
{
  addInstr("je "+label);
}

void ASMWriter_x86::addInstrJmpIfGreater(string label)
{
  addInstr("jg "+label);
}

void ASMWriter_x86::addInstrJmpIfGreaterOrEqual(string label)
{
  addInstr("jge "+label);
}

void ASMWriter_x86::addInstrJmpIfNotEqual(string label)
{
  addInstr("jne "+label);
}

void ASMWriter_x86::addInstrJmpIfInferior(string label)
{
  addInstr("jl "+label);
}

void ASMWriter_x86::addInstrJmpIfInferiorOrEqual(string label)
{
  addInstr("jle "+label);
}

void ASMWriter_x86::addInstrCmp(string src, string dest)
{
  addInstr("cmp "+dest+", "+src);
}

void ASMWriter_x86::addPrologue(int stackFrameSize, int nbParams)
{
  addInstr("pushq %rbp");
  addInstrMov("%rsp", "%rbp", 8);
  addInstrSub(string("$")+to_string(stackFrameSize+4), "%rsp", 8);
  for(int i = 0; i<nbParams; i++)
  {
    addInstrMov(registers[i],to_string(-(i+1)*4)+"(%rbp)");
  }
}

void ASMWriter_x86::addEpilogue()
{
  addInstr("leave");
  addInstr("ret");
}


void ASMWriter_x86::addAffectationInt(int addr, int value, uint size)
{
  addInstrMov(string("$")+to_string(value),to_string(addr)+string("(%rbp)"),size);
}

int ASMWriter_x86::addAddition(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrAdd(string("%edx"),string("%eax"),size);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter_x86::addSubstraction(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%edx"),size);
  // ici on fait addr1 - addr2 a priori
  // => mettre addr1 dans edx et addr2 dans eax au dessus pour inverser
  addInstrSub(string("%edx"),string("%eax"),size);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter_x86::addMultiplication(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%edx"),size);
  addInstrMult(string("%edx"));
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter_x86::addDivision(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%ebx"),size);
  addInstrDiv(string("%ebx"));
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter_x86::addCmp(int addr, int value, uint size){
  addInstrCmp(to_string(addr)+string("(%rbp)"),string("$")+to_string(value));
  return 0;
}

int ASMWriter_x86::addComparison(int addrRes, int addr1, int addr2, cmp c, string labelModifier, uint size){
  switch (c)
  {
    case eq:
      addComparisonEqual(addrRes, addr1, addr2, labelModifier, size);
      break;
    case ge:
      addComparisonSupEqual(addrRes, addr1, addr2, labelModifier, size);
      break;
    case gt:
      addComparisonSupStrict(addrRes, addr1, addr2, labelModifier, size);
      break;
    case neq:
      addComparisonNotEqual(addrRes, addr1, addr2, labelModifier, size);
      break;
    case le:
      addComparisonInfEqual(addrRes, addr1, addr2, labelModifier, size);
      break;
    case lt:
      addComparisonInfStrict(addrRes, addr1, addr2, labelModifier, size);
      break;

    default:
      break;
  }
  return addrRes;
}

int ASMWriter_x86::addComparisonEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string equal = labelModifier+"equal";
  string end = labelModifier+"end";
  addInstrJmpIfEqual(equal);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(equal);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addComparisonSupEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string greaterOrEqual = labelModifier+"greaterOrEqual";
  string end = labelModifier+"end";
  addInstrJmpIfGreaterOrEqual(greaterOrEqual);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(greaterOrEqual);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addComparisonSupStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string greater = labelModifier+"greater";
  string end = labelModifier+"end";
  addInstrJmpIfGreater(greater);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(greater);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addComparisonNotEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string notEqual = labelModifier+"notEqual";
  string end = labelModifier+"end";
  addInstrJmpIfNotEqual(notEqual);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(notEqual);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addComparisonInfEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string inferiorOrEqual = labelModifier+"inferiorOrEqual";
  string end = labelModifier+"end";
  addInstrJmpIfInferiorOrEqual(inferiorOrEqual);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(inferiorOrEqual);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addComparisonInfStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrCmp(string("%edx"),string("%eax"));
  string inferior = labelModifier+"inferior";
  string end = labelModifier+"end";
  addInstrJmpIfInferior(inferior);
  addAffectationInt(addrRes, 0, size);
  addInstrJmp(end);
  addLabel(inferior);
  addAffectationInt(addrRes, 1, size);
  addLabel(end);

  return addrRes;
}

int ASMWriter_x86::addCall(string label, int addrRes, uint size, vector<int> params){
  int i = 0;
  for(auto p : params)
  {
    addInstrMov(to_string(p)+"(%rbp)",registers[i++]);
  }
  addInstrCall(label);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter_x86::addReadMem(int addrDest, int addrMem, uint size){
  addInstrMov(to_string(addrMem)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(string("%edx"),to_string(addrDest)+string("(%rbp)"),size);
}

int ASMWriter_x86::addWriteMem(int addrMem, int addrSrc, uint size){
  addInstrMov(to_string(addrSrc)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(string("%edx"),to_string(addrMem)+string("(%rbp)"),size);
}

void ASMWriter_x86::addReturnVar(int addr, string fctName, uint size)
{
  addInstrMov(to_string(addr)+string("(%rbp)"),string("%eax"),size);
}

void ASMWriter_x86::addReturnInt(int value, string fctName)
{
  addInstrMov(string("$")+to_string(value),"%eax");
}

int ASMWriter_x86::addNeg(int addr, uint size)
{
    addInstrMov(to_string(addr)+string("(%rbp)"),string("%eax"),size);
	  addInstrNeg(string("%eax"));
    addInstrMov(string("%eax"),to_string(addr)+string("(%rbp)"),size);
    return addr;
}

int ASMWriter_x86::addJmp(string label)
{
  addInstrJmp(label);
  return 0;
}

int ASMWriter_x86::addJmpIfEqual(string label)
{
  addInstrJmpIfEqual(label);
  return 0;
}

int ASMWriter_x86::addJmpIfGreater(string label)
{
  addInstrJmpIfGreater(label);
  return 0;
}

int ASMWriter_x86::addJmpIfGreaterOrEqual(string label)
{
  addInstrJmpIfGreaterOrEqual(label);
  return 0;
}

int ASMWriter_x86::addJmpIfNotEqual(string label)
{
  addInstrJmpIfNotEqual(label);
  return 0;
}

int ASMWriter_x86::addJmpIfInferior(string label)
{
  addInstrJmpIfInferior(label);
  return 0;
}

int ASMWriter_x86::addJmpIfInferiorOrEqual(string label)
{
  addInstrJmpIfInferiorOrEqual(label);
  return 0;
}
