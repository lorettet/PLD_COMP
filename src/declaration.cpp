#include "symboles.h"
#include "ASMWriter.h"
#include <iostream>
using namespace std;

string Declaration::getNomVariable() {
	return variable->getNomVariable();
}

string DeclarationSimple::buildIR(CFG & cfg)
{
	cout << "Simple Declaration" << endl;
}

string DeclarationAvecAffectation::buildIR(CFG & cfg)
{
	cout << "Building IR Declaration + Affec" << endl;
	cout << "Getting right" << endl;
	string right = expression->buildIR(cfg);
	cout << "Getting left" << endl;
	string left = variable->buildIR(cfg);
	IRInstr_wmem* instr = new IRInstr_wmem(cfg.current_bb,Type::Int32,cfg.get_var_index(left),right);
	cout << "Adding Dec + Affec" << endl;
	cfg.current_bb->add_IRInstr(instr);
	return right;
}
