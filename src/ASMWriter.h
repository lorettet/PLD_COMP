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

  void addReturnVar(int addr, uint size = 4);

  void addReturnInt(int value);

  void addAffectationInt(int addr, int value, uint size = 4);

  void addAffectationVar(int dest, int src, uint size = 4);

  // void addAddition(int value1, int value2);

  int addAddition(int addrRes, int addr1, int addr2, uint size = 4);

  // void addAddition(string name, int value);

  // void addAddition(string name1, string name2);

  // void addAdditionAndAffectation(string dest, int value1, int value2);

  // void addAdditionAndAffectation(string dest, string nameAdd, int value);

  // void addAdditionAndAffectation(string dest, string nameAdd1, string nameAdd2);

  int addSubstraction(int addrRes, int addr1, int addr2, uint size = 4);

  int addMultiplication(int addrRes, int addr1, int addr2, uint size = 4);

  int addDivision(int addrRes, int addr1, int addr2, uint size = 4);

  int addReadMem(int addrDest, int addrMem, uint size = 4);

  int addWriteMem(int addrMem, int addrSrc, uint size = 4);

  void writeASM();

  void addPrologue();

  void addEpilogue();

private:
  void initDoc();


  void addLabel(string name);

  void addInstr(string instr);

  void addInstrMov(string src, string dest, uint size = 4);

  void addInstrAdd(string src, string dest, uint size = 4);

  void addInstrSub(string src, string dest, uint size = 4);
  
  void addInstrMult(string src);
  
  void addInstrDiv(string src);

  ofstream fileStream;
  string fileName;
  vector<string> lines;


};
