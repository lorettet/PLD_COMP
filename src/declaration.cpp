#include "symboles.h"
#include "ASMWriter.h"
#include <iostream>
using namespace std;

string Declaration::getNomVariable() {
	return variable->getNomVariable();
}

string DeclarationSimple::buildIR(CFG & cfg)
{
	cout << "-= Simple Declaration =-" << endl;
	return "";
}

string DeclarationAvecAffectation::buildIR(CFG & cfg)
{
	cout << "-= Building IR Declaration + Affec =-" << endl;
	cout << "Getting right" << endl;
	string right = expression->buildIR(cfg);
	cout << "Getting left" << endl;
	string left = variable->buildIR(cfg);
	IRInstr_wmem* instr = new IRInstr_wmem(cfg.current_bb,Type::Int32,cfg.current_bloc,cfg.get_var_index(left,cfg.current_bloc),right);
	cout << "Adding IR Dec + Affec" << endl;
	cfg.current_bb->add_IRInstr(instr);
	return right;
}

string DeclarationTabSimple::buildIR(CFG & cfg)
{
	cout << "-= Simple Tab Declaration =-" << endl;
	return "";
}

string DeclarationTabAvecAffectation::buildIR(CFG & cfg)
{
	cout << "-= Building IR Declaration Tab + Affec =-" << endl;
	cout << "Getting right" << endl;
	int i = 0;
	string left = variable->buildIR(cfg);
	for(auto expr : expression->tabExpressions)
	{
		string var = expr->buildIR(cfg);
		IRInstr_wmem* instr = new IRInstr_wmem(cfg.current_bb,Type::Int32,cfg.current_bloc,cfg.get_var_index(left,cfg.current_bloc),var,i);
		cfg.current_bb->add_IRInstr(instr);
		i++;
	}
	return "";
}
