#include "symboles.h"
#include <string>
#include <iostream>
using namespace std;

string Addition::buildIR(CFG & cfg)
{
  cout << "Building IR Add" << endl;
  cout << "Getting exp1" << endl;
  string var1 = exp1->buildIR(cfg);
  cout << "Getting exp2" << endl;
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_add* add = new IRInstr_add(cfg.current_bb,Type::Int32,var,var1,var2);
  cout << "Adding IR Add" << endl;
  cfg.current_bb->add_IRInstr(add);
  return var;
}
