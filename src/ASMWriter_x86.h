#pragma once

#include "ASMWriter.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

class ASMWriter_x86 : public ASMWriter
{
public:
  ASMWriter_x86(string name);
  virtual ~ASMWriter_x86(){}

  virtual void addReturnVar(int addr,string fctName, uint size = 4);

  virtual void addReturnInt(int value, string fctName);

  virtual void addAffectationInt(int addr, int value, uint size = 4);

  virtual int addAddition(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addSubstraction(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addMultiplication(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addCall(string label, int addrRes, uint size, vector<int> params);

  virtual int addDivision(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addCmp(int addr, int value, uint size = 4);

  virtual int addComparison(int addrRes, int addr1, int addr2, cmp c, string labelModifier, uint size = 4);

  virtual int addComparisonEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addComparisonSupEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addComparisonSupStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addComparisonNotEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addComparisonInfEqual(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addComparisonInfStrict(int addrRes, int addr1, int addr2, string labelModifier, uint size);

  virtual int addReadMem(int addrDest, int addrMem, uint index,  uint size = 4);
  virtual int addReadMemIndex(int addrDest, int addrMem, int index,  uint size = 4);

  virtual int addWriteMem(int addrMem, int addrSrc, uint index, uint size = 4);
  virtual int addWriteMemIndex(int addrMem, int addrSrc, int index, uint size = 4);

  virtual int addJmp(string label);

  virtual int addJmpIfEqual(string label);

  virtual int addJmpIfGreater(string label);

  virtual int addJmpIfGreaterOrEqual(string label);

  virtual int addJmpIfNotEqual(string label);

  virtual int addJmpIfInferior(string label);

  virtual int addJmpIfInferiorOrEqual(string label);

  virtual int addNeg(int addr, uint size = 4);

  virtual void addPrologue(int stackFrameSize, int nbParams);

  virtual void addEpilogue();

protected:

  string registers[6] = {"%edi","%esi","%edx","%ecx","%r8d","%r9d"};

  virtual void addInstrMov(string src, string dest, uint size = 4);

  virtual void addInstrAdd(string src, string dest, uint size = 4);

  virtual void addInstrSub(string src, string dest, uint size = 4);

  virtual void addInstrDiv(string src);

  virtual void addInstrMult(string src);

  virtual void addInstrCall(string label);

  virtual void addInstrNeg(string src);

  virtual void addInstrJmp(string label);

  virtual void addInstrJmpIfEqual(string label);

  virtual void addInstrJmpIfGreater(string label);

  virtual void addInstrJmpIfGreaterOrEqual(string label);

  virtual void addInstrJmpIfNotEqual(string label);

  virtual void addInstrJmpIfInferior(string label);

  virtual void addInstrJmpIfInferiorOrEqual(string label);

  virtual void addInstrCmp(string src, string dest);
};
