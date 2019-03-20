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

void ASMWriter::initDoc()
{
  addInstr(".text");
  addInstr(".global main");
  addLabel("main");
  addPrologue();
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

void ASMWriter::addDeclaration(string name, uint size)
{
  symTab[name] = lastSymOffset-size;
  lastSymOffset -= size;
}

void ASMWriter::addAffectation(string name, int value)
{
  addInstrMov(string("$")+to_string(value),to_string(symTab[name])+string("(%rbp)"));
}

void ASMWriter::addAffectation(string dest, string src)
{
  addInstrMov(to_string(symTab[src])+string("(%rbp)"),string("%edx"));
  addInstrMov(string("%edx"),to_string(symTab[dest])+string("(%rbp)"));
}

void ASMWriter::addDeclarationAndAffectation(string name, int value, uint size)
{
  addDeclaration(name);
  addAffectation(name, value);
}

void ASMWriter::addDeclarationAndAffectation(string dest, string src, uint size)
{
  addDeclaration(dest);
  addAffectation(dest, src);
}

void ASMWriter::addAddition(int value1, int value2){
  int temp = value1 + value2;
  addInstrMov(string("$")+to_string(temp),string("%eax"));
  //return registre ?
}

void ASMWriter::addAddition(string nameAdd, int value){
  addInstrMov(to_string(symTab[nameAdd])+string("(%rbp)"),string("%eax"));
  addInstrAdd(string("$")+to_string(value),string("%eax"));
  //return registre ?
}

void ASMWriter::addAddition(string nameAdd1, string nameAdd2){
  addInstrMov(to_string(symTab[nameAdd1])+string("(%rbp)"),string("%edx"));
  addInstrMov(to_string(symTab[nameAdd2])+string("(%rbp)"),string("%eax"));
  addInstrAdd(string("%edx"),string("%eax"));
  //return registre ?
}

void ASMWriter::addAdditionAndAffectation(string dest, int value1, int value2){
  int temp = value1 + value2;
  addInstrMov(string("$")+to_string(temp),to_string(symTab[dest])+string("(%rbp)"));
  //return registre ?
}

void ASMWriter::addAdditionAndAffectation(string dest, string nameAdd, int value){
  addInstrMov(to_string(symTab[nameAdd])+string("(%rbp)"),string("%eax"));
  addInstrAdd(string("$")+to_string(value),string("%eax"));
  addInstrMov(string("%eax"),to_string(symTab[dest])+string("(%rbp)"));
  //return registre ?
}

void ASMWriter::addAdditionAndAffectation(string dest, string nameAdd1, string nameAdd2){
  addInstrMov(to_string(symTab[nameAdd1])+string("(%rbp)"),string("%edx"));
  addInstrMov(to_string(symTab[nameAdd2])+string("(%rbp)"),string("%eax"));
  addInstrAdd(string("%edx"),string("%eax"));
  addInstrMov(string("%eax"),to_string(symTab[dest])+string("(%rbp)"));
  //return registre ?
}

void ASMWriter::addReturn(string name)
{
  addInstrMov(to_string(symTab[name])+string("(%rbp)"),"%eax");
  addEpilogue();
}

void ASMWriter::addReturn(int value)
{
  addInstrMov(value,"%eax");
  addEpilogue();
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
