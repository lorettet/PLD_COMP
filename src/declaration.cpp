#include "symboles.h"
#include "ASMWriter.h"
#include <iostream>
using namespace std;

string Declaration::getNomVariable() {
	return variable->getNomVariable();
}

void DeclarationSimple::getASM(ASMWriter & asmb)
{
	cout << "DeclarationSimple" << endl;
	asmb.addDeclaration(variable->getNomVariable());
}

//TODO : revoir un autre moyen
void DeclarationAvecAffectation::getASM(ASMWriter & asmb)
{
	if(dynamic_cast<Int*>(expression))
	{
		cout << "Declaration + Affectation : int" << endl;
		asmb.addDeclarationAndAffectation(variable->getNomVariable(),((Int*)expression)->getValue());
	}
	else if(dynamic_cast<Variable*>(expression))
	{
		cout << "Declaration + Affectationtion : var" << endl;
		asmb.addDeclarationAndAffectation(variable->getNomVariable(),((Variable*)expression)->getNomVariable());
	}

}
