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

  typedef enum
  {
    eq=1,
    ge=2,
    gt=3,
    neq=-1,
    le=-2,
    lt=-3
  } cmp;

  ASMWriter(string name);

  virtual ~ASMWriter(){}

  virtual void addReturnVar(int addr, string fctName ,uint size = 4) = 0;

  virtual void addReturnInt(int value, string fctName) = 0;

  virtual void addAffectationInt(int addr, int value, uint size = 4) = 0;

  virtual int addAddition(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addSubstraction(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addMultiplication(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addCall(string label, int addrRes, uint size, vector<int> params) = 0;

  virtual int addDivision(int addrRes, int addr1, int addr2, uint size = 4) = 0;

  virtual int addCmp(int addr, int value, uint size = 4) = 0;

  virtual int addComparison(int addrRes, int addr1, int addr2, cmp c, string labelModifier, uint size = 4) = 0;

  virtual int addComparisonEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addComparisonSupEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addComparisonSupStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addComparisonNotEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addComparisonInfEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addComparisonInfStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size) = 0;

  virtual int addReadMem(int addrDest, int addrMem, uint index, uint size = 4) = 0;

  virtual int addWriteMem(int addrMem, int addrSrc, uint index, uint size = 4) = 0;

  virtual int addJmp(string label) = 0;

  virtual int addJmpIfEqual(string label) = 0;

  virtual int addJmpIfGreater(string label) = 0;

  virtual int addJmpIfGreaterOrEqual(string label) = 0;

  virtual int addJmpIfNotEqual(string label) = 0;

  virtual int addJmpIfInferior(string label) = 0;

  virtual int addJmpIfInferiorOrEqual(string label) = 0;

  virtual int addNeg(int addr, uint size = 4) = 0;

  virtual void writeASM();

  virtual void addPrologue(int stackFrameSize, int nbParams) = 0;

  virtual void addEpilogue() = 0;

  virtual void initFunction(string name);

  virtual void addLabel(string name);

protected:
  virtual void initDoc();

  virtual void addInstr(string instr);

  virtual void addInstrMov(string src, string dest, uint size = 4) = 0;

  virtual void addInstrAdd(string src, string dest, uint size = 4) = 0;

  virtual void addInstrSub(string src, string dest, uint size = 4) = 0;

  virtual void addInstrDiv(string src) = 0;

  virtual void addInstrMult(string src) = 0;

  virtual void addInstrCall(string label) = 0;

  virtual void addInstrNeg(string src) = 0;

  virtual void addInstrJmp(string label) = 0;

  virtual void addInstrJmpIfEqual(string label) = 0;

  virtual void addInstrJmpIfGreater(string label) = 0;

  virtual void addInstrJmpIfGreaterOrEqual(string label) = 0;

  virtual void addInstrJmpIfNotEqual(string label) = 0;

  virtual void addInstrJmpIfInferior(string label) = 0;

  virtual void addInstrJmpIfInferiorOrEqual(string label) = 0;

  virtual void addInstrCmp(string src, string dest) = 0;

  ofstream fileStream;
  string fileName;
  vector<string> lines;


};
