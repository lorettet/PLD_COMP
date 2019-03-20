#include "symboles.h"

void Return::getASM(ASMWriter & asmb)
{
  if(dynamic_cast<Int*>(expression))
	{
		cout << "Return int" << endl;
		asmb.addReturn(((Int*)expression)->getValue());
	}
	else if(dynamic_cast<Variable*>(expression))
	{
		cout << "Return var" << endl;
		asmb.addReturn(((Variable*)expression)->getNomVariable());
	}
}

void Affectation::getASM(ASMWriter & asmb)
{
  if(dynamic_cast<Int*>(expression))
  {
    cout << "Return int" << endl;
    asmb.addAffectation(variable->getNomVariable(),((Int*)expression)->getValue());
  }
  else if(dynamic_cast<Variable*>(expression))
  {
    cout << "Return var" << endl;
    asmb.addAffectation(variable->getNomVariable(),((Variable*)expression)->getNomVariable());
  }
}
