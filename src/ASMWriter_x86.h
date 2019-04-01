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

  virtual void addReturnVar(int addr, uint size = 4);

  virtual void addReturnInt(int value);

  virtual void addAffectationInt(int addr, int value, uint size = 4);

  virtual int addAddition(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addSubstraction(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addMultiplication(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addDivision(int addrRes, int addr1, int addr2, uint size = 4);

  virtual int addReadMem(int addrDest, int addrMem, uint size = 4);

  virtual int addWriteMem(int addrMem, int addrSrc, uint size = 4);

  virtual void addPrologue();

  virtual void addEpilogue();

protected:

  virtual void addInstrMov(string src, string dest, uint size = 4);

  virtual void addInstrAdd(string src, string dest, uint size = 4);

  virtual void addInstrSub(string src, string dest, uint size = 4);
};
