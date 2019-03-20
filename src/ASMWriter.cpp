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

void ASMWriter::addInstrMov(int value, string dest)
{
    addInstr("movl $"+to_string(value)+", "+dest);
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


void ASMWriter::addAffectationInt(int addr, int value)
{
  addInstrMov(string("$")+to_string(value),to_string(addr)+string("(%rbp)"));
}

void ASMWriter::addAffectationVar(int dest, int src)
{
  addInstrMov(to_string(src)+string("(%rbp)"),string("%edx"));
  addInstrMov(string("%edx"),to_string(dest)+string("(%rbp)"));
}

void ASMWriter::addReturnVar(int addr)
{
  addInstrMov(to_string(addr)+string("(%rbp)"),"%eax");
  addEpilogue();
}

void ASMWriter::addReturnInt(int value)
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
