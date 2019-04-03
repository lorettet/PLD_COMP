#include "symboles.h"

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
