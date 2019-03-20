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

void Affectation::getASM(ASMWriter & asmb, map<string,int> var)
{
  if(dynamic_cast<Int*>(expression))
  {
    cout << "Return int" << endl;
    int addr = var[variable->getNomVariable()];
    asmb.addAffectationInt(addr,((Int*)expression)->getValue());
  }
  else if(dynamic_cast<Variable*>(expression))
  {
    cout << "Return var" << endl;
    int dest = var[variable->getNomVariable()];
    int src = var[((Variable*)expression)->getNomVariable()];
    asmb.addAffectationVar(dest,src);
  }
}
