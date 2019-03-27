#include "symboles.h"
#include "type.h"

string Int::buildIR(CFG & cfg)
{
  Int32 t();
  string var = cfg.create_new_tempvar(t);
  IRInstr_ldconst instr(var, valeur);
  cfg.current_bb->add_IRInstr(instr);
  return var;
}

string Variable::buildIR(CFG & cfg)
{
  return nom;
}
