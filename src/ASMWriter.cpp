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

void ASMWriter::initDoc()
{
  addInstr(".text");
  addInstr(".global main");
  addLabel("main");
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
