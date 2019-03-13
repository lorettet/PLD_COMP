#include "symboles.h"

void Fonction::ajouterDeclaration(Declaration* dec) {
	declarations.push_back(dec);
	variables[dec->getNomVariable()] = index;
	index += 4;
}

void Fonction::ajouterInstruction(Instruction* inst) {
	instructions.push_back(inst);
}
