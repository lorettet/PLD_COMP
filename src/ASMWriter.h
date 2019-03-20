#pragma once

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class ASMWriter
{
public:
  ASMWriter(string name);

  ~ASMWriter(){}

  void addReturnVar(int addr);

  void addReturnInt(int value);

  void addAffectationInt(int addr, int value);

  void addAffectationVar(int dest, int src);

  void writeASM();

private:
  void initDoc();

  void addPrologue();

  void addEpilogue();

  void addLabel(string name);

  void addInstr(string instr);

  void addInstrMov(string src, string dest, uint size = 4);

  void addInstrMov(int value, string dest);

  ofstream fileStream;
  string fileName;
  vector<string> lines;

  map<string, int> symTab;
  int lastSymOffset = 0;
};
