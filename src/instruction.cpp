#include "symboles.h"

void Return::getASM(ASMWriter & asmb, map<string,int> var)
{
  if(dynamic_cast<Int*>(expression))
	{
		cout << "Return int" << endl;
		asmb.addReturnInt(((Int*)expression)->getValue());
	}
	else if(dynamic_cast<Variable*>(expression))
	{
		cout << "Return var" << endl;
    int addr = var[((Variable*)expression)->getNomVariable()];
		asmb.addReturnVar(addr);
	}
}

string Affectation::buildIR(CFG & cfg)
{
  string right = expression->buildIR(cfg);
  string left = variable->buildIR(cfg);
  IRInstr_wmem instr = new IRInstr_wmem(left,right);
  return right;
}

string Return::buildIR(CFG & cfg)
{
  
}
