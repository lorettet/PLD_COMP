#include "symboles.h"
#include <sstream>

using namespace std;

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

void Fonction::buildIR(CFG & cfg)
{
  cout << "-= Build IR Fonction : " << nom << " =-" << endl;
  cout << "Adding params" << endl;
  stringstream ss;
  ss << bloc;
  string pointerString = ss.str();
  for(auto p : params->listParams)
  {
    cfg.add_to_symbol_table(p->nom+pointerString,Type::Int32);
  }
  bloc->buildIR(cfg);
}
