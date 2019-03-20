#include "symboles.h"
#include "ASMWriter.h"
#include <iostream>
using namespace std;

string Declaration::getNomVariable() {
	return variable->getNomVariable();
}

void DeclarationSimple::getASM(ASMWriter & asmb, map<string,int> var)
{
	cout << "DeclarationSimple" << endl;
}

//TODO : revoir un autre moyen
void DeclarationAvecAffectation::getASM(ASMWriter & asmb, map<string,int> var)
{
	if(dynamic_cast<Int*>(expression))
	{
		cout << "Declaration + Affectation : int" << endl;
		int addr = var[variable->getNomVariable()];
		asmb.addAffectationInt(addr,((Int*)expression)->getValue());
	}
	else if(dynamic_cast<Variable*>(expression))
	{
		cout << "Declaration + Affectationtion : var" << endl;
		int dest = var[variable->getNomVariable()];
		int src = var[((Variable*)expression)->getNomVariable()];
		asmb.addAffectationVar(dest,src);
	}

}
