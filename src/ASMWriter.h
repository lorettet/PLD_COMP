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

  void addAddition(int value1, int value2);

  void addAddition(string name, int value);

  void addAddition(string name1, string name2);

  void addAdditionAndAffectation(string dest, int value1, int value2);
  
  void addAdditionAndAffectation(string dest, string nameAdd, int value);

  void addAdditionAndAffectation(string dest, string nameAdd1, string nameAdd2);

  void writeASM();

private:
  void initDoc();

  void addPrologue();

  void addEpilogue();

  void addLabel(string name);

  void addInstr(string instr);

  void addInstrMov(string src, string dest, uint size = 4);

  void addInstrAdd(string src, string dest, uint size = 4);

  ofstream fileStream;
  string fileName;
  vector<string> lines;

  map<string, int> symTab;
  int lastSymOffset = 0;
};
