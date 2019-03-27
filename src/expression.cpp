#include "symboles.h"
#include <string>

string Addition::buildIR(CFG & cfg)
{
  string var1 = exp1->buildIR(cfg);
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_add* add = new IRInstr(var,var1,var2);
  cfg.current_bb->add_IRInstr(add);
  return var;
}
