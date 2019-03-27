#include "symboles.h"
#include "ASMWriter.h"
#include <iostream>
using namespace std;

string Declaration::getNomVariable() {
	return variable->getNomVariable();
}

void DeclarationSimple::buildIR(ASMWriter & asmb)
{

}

void DeclarationAvecAffectation::buildIR(ASMWriter & asmb)
{
	string right = expression->buildIR(cfg);
	string left = variable->buildIR(cfg);
	IRInstr_wmem instr = new IRInstr_wmem(left,right);
	return right;
}
