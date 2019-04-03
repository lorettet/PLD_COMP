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

  virtual ~ASMWriter(){}

  virtual void addReturnVar(int addr, uint size = 4) = 0;

  virtual void addReturnInt(int value) = 0;

  virtual void addAffectationInt(int addr, int value, uint size = 4) = 0;

  virtual int addAddition(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addSubstraction(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addMultiplication(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addCall(string label, int addrRes, uint size, vector<int> params) = 0;

  virtual int addDivision(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addReadMem(int addrDest, int addrMem, uint size = 4) = 0;

  virtual int addWriteMem(int addrMem, int addrSrc, uint size = 4) = 0;

  virtual void writeASM();

  virtual void addPrologue(int stackFrameSize) = 0;

  virtual void addEpilogue() = 0;

  virtual void initFunction(string name);

protected:
  virtual void initDoc();

  virtual void addLabel(string name);

  virtual void addInstr(string instr);

  virtual void addInstrMov(string src, string dest, uint size = 4) = 0;

  virtual void addInstrAdd(string src, string dest, uint size = 4) = 0;

  virtual void addInstrSub(string src, string dest, uint size = 4) = 0;

  virtual void addInstrDiv(string src) = 0;

  virtual void addInstrMult(string src) = 0;

  virtual void addInstrCall(string label) = 0;

  ofstream fileStream;
  string fileName;
  vector<string> lines;


};
