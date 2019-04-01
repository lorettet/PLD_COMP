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

vector<CFG*> Programme::buildIR()
{
  vector<CFG*> res;
  for(auto f : fonctions)
  {
    CFG* c = new CFG(f);
    c->buildIR();
    res.push_back(c);
  }
  return res;
}
