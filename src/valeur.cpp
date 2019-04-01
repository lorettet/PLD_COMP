#include "symboles.h"
#include "type.h"
#include <iostream>
using namespace std;

string Int::buildIR(CFG & cfg)
{
  cout << "Building IR Int : " << valeur << endl;
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_ldconst* instr = new IRInstr_ldconst(cfg.current_bb,Type::Int32,var, valeur);
  cfg.current_bb->add_IRInstr(instr);
  return var;
}

string Variable::buildIR(CFG & cfg)
{
  cout << "var is " << nom << endl;
  return nom;
}

string Appel::buildIR(CFG & cfg)
{
  return "";
}
