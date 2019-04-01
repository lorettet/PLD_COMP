#include "ASMWriter.h"
#include <sstream>
#include <iostream>

ASMWriter::ASMWriter(string name): fileName(name)
{
  initDoc();
}

void ASMWriter::addLabel(string label)
{
  lines.push_back(label+":");
}

void ASMWriter::addInstr(string instr)
{
  lines.push_back("\t"+instr);
}

void ASMWriter::addInstrMov(string src, string dest, uint size)
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

void ASMWriter::addInstrAdd(string src, string dest, uint size)
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

void ASMWriter::addInstrSub(string src, string dest, uint size)
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

void ASMWriter::addInstrMult(string src)
{
      addInstr("imul "+src);
}

void ASMWriter::addInstrDiv(string src)
{
	  addInstr("cltd");
      addInstr("idivl "+src);
}

void ASMWriter::initDoc()
{
  addInstr(".text");
  addInstr(".global main");
  addLabel("main");
}

void ASMWriter::addPrologue()
{
  addInstr("pushq %rbp");
  addInstrMov("%rsp", "%rbp", 8);
}

void ASMWriter::addEpilogue()
{
  addInstr("popq %rbp");
  addInstr("ret");
}


void ASMWriter::addAffectationInt(int addr, int value, uint size)
{
  addInstrMov(string("$")+to_string(value),to_string(addr)+string("(%rbp)"),size);
}

// void ASMWriter::addAffectationVar(int dest, int src, uint size)
// {
//   addInstrMov(to_string(src)+string("(%rbp)"),string("%edx"),size);
//   addInstrMov(string("%edx"),to_string(dest)+string("(%rbp)"),size);
// }

// void ASMWriter::addAddition(int value1, int value2){
//   int temp = value1 + value2;
//   addInstrMov(string("$")+to_string(temp),string("%eax"));
//   //return adresse ?
// }

int ASMWriter::addAddition(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%eax"),size);
  addInstrAdd(string("%edx"),string("%eax"),size);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
  //return adresse ?
}

int ASMWriter::addSubstraction(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%edx"),size);
  // ici on fait addr1 - addr2 a priori
  // => mettre addr1 dans edx et addr2 dans eax au dessus pour inverser
  addInstrSub(string("%edx"),string("%eax"),size);
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
  //return adresse ?
}

int ASMWriter::addMultiplication(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%edx"),size);
  addInstrMult(string("%edx"));
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter::addDivision(int addrRes, int addr1, int addr2, uint size){
  addInstrMov(to_string(addr1)+string("(%rbp)"),string("%eax"),size);
  addInstrMov(to_string(addr2)+string("(%rbp)"),string("%ebx"),size);
  addInstrDiv(string("%ebx"));
  addInstrMov(string("%eax"),to_string(addrRes)+string("(%rbp)"),size);
  return addrRes;
}

int ASMWriter::addReadMem(int addrDest, int addrMem, uint size){
  addInstrMov(to_string(addrMem)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(string("%edx"),to_string(addrDest)+string("(%rbp)"),size);
}

int ASMWriter::addWriteMem(int addrMem, int addrSrc, uint size){
  addInstrMov(to_string(addrSrc)+string("(%rbp)"),string("%edx"),size);
  addInstrMov(string("%edx"),to_string(addrMem)+string("(%rbp)"),size);
}

// void ASMWriter::addAddition(string nameAdd, int value){
//   addInstrMov(to_string(symTab[nameAdd])+string("(%rbp)"),string("%eax"));
//   addInstrAdd(string("$")+to_string(value),string("%eax"));
//   //return adresse ?
// }

// void ASMWriter::addAddition(string nameAdd1, string nameAdd2){
//   addInstrMov(to_string(symTab[nameAdd1])+string("(%rbp)"),string("%edx"));
//   addInstrMov(to_string(symTab[nameAdd2])+string("(%rbp)"),string("%eax"));
//   addInstrAdd(string("%edx"),string("%eax"));
//   //return registre ?
// }

// void ASMWriter::addAdditionAndAffectation(string dest, int value1, int value2){
//   int temp = value1 + value2;
//   addInstrMov(string("$")+to_string(temp),to_string(symTab[dest])+string("(%rbp)"));
//   //return registre ?
// }

// void ASMWriter::addAdditionAndAffectation(string dest, string nameAdd, int value){
//   addInstrMov(to_string(symTab[nameAdd])+string("(%rbp)"),string("%eax"));
//   addInstrAdd(string("$")+to_string(value),string("%eax"));
//   addInstrMov(string("%eax"),to_string(symTab[dest])+string("(%rbp)"));
//   //return registre ?
// }

// void ASMWriter::addAdditionAndAffectation(string dest, string nameAdd1, string nameAdd2){
//   addInstrMov(to_string(symTab[nameAdd1])+string("(%rbp)"),string("%edx"));
//   addInstrMov(to_string(symTab[nameAdd2])+string("(%rbp)"),string("%eax"));
//   addInstrAdd(string("%edx"),string("%eax"));
//   addInstrMov(string("%eax"),to_string(symTab[dest])+string("(%rbp)"));
//   //return registre ?
// }

void ASMWriter::addReturnVar(int addr, uint size)
{
  addInstrMov(to_string(addr)+string("(%rbp)"),string("%eax"),size);
}

void ASMWriter::addReturnInt(int value)
{
  addInstrMov(string("$")+to_string(value),"%eax");
}

void ASMWriter::writeASM()
{

  fileStream.open(fileName); // TODO: catch exception
  for(auto l : lines)
  {
    fileStream << l << endl;
  }
  fileStream.close();
}
