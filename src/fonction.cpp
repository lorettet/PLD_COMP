#include <assert.h> 
#include "symboles.h"

using namespace std;

void Fonction::ajouterDeclaration(Declaration* dec) {
	assert(variables.find(dec->getNomVariable()) == variables.end());
	declarations.push_back(dec);
	variables[dec->getNomVariable()] = index;
	index += 4;
}

void Fonction::ajouterInstruction(Instruction* inst) {
	instructions.push_back(inst);
}

void Fonction::getASM(ASMWriter & asmb)
{
	for(auto dec : declarations)
	{
		dec->getASM(asmb, variables);
	}
	for(auto instr : instructions)
	{
		instr->getASM(asmb, variables);
	}
}
