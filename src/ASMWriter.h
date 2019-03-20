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

  void addReturn(string name);

  void addReturn(int value);

  void addAffectation(string name, int value);

  void addAffectation(string dest, string src);

  void addDeclaration(string name, uint size = 4);

  void addDeclarationAndAffectation(string name, int value, uint size = 4);

  void addDeclarationAndAffectation(string dest, string src, uint size = 4);

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
