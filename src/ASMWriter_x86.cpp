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

void ASMWriter_x86::addPrologue(int stackFrameSize, int nbParams)
{
  addInstr("pushq %rbp");
  addInstrMov("%rsp", "%rbp", 8);
  addInstrSub(string("$")+to_string(stackFrameSize+4), "%rsp", 8);
  for(int i = 0; i<nbParams; i++)
  {
    addInstrMov(registers[i],-(i+1)*4+"(%rbp)");
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
  //return adresse ?
}

int ASMWriter_x86::addSubstraction(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%edx"),size);
  // ici on fait addr1 - addr2 a priori
  // => mettre addr1 dans edx et addr2 dans eax au dessus pour inverser
  addInstrSub(string("%edx"),string("%eax"),size);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
  //return adresse ?
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

int ASMWriter_x86::addCall(string label, int addrRes, uint size, vector<int> params){
  int i = 0;
  for(auto p : params)
  {
    addInstrMov(to_string(p)+"(%rbp)","%"+registers[i++]);
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

void ASMWriter_x86::addReturnVar(int addr, uint size)
{
  addInstrMov(to_string(addr)+string("(%rbp)"),string("%eax"),size);
}

void ASMWriter_x86::addReturnInt(int value)
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
