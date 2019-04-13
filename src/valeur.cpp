#include "symboles.h"
#include "type.h"
#include <iostream>
using namespace std;

string Int::buildIR(CFG & cfg)
{
  cout << "- =Building IR Int : " << valeur << " =-" << endl;
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_ldconst* instr = new IRInstr_ldconst(cfg.current_bb,Type::Int32,cfg.current_bloc,var, valeur);
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
  cout << "-= Building IR Appel : " << nomFonction << " =-" << endl;
  string var = cfg.create_new_tempvar(Type::Int32);
  vector<string> tempExp;
  for(auto exp : params->listExpr)
  {
    string temp = cfg.create_new_tempvar(Type::Int32);
    temp = exp->buildIR(cfg);
    tempExp.push_back(temp);
  }
  IRInstr_call* call = new IRInstr_call(cfg.current_bb,Type::Int32,cfg.current_bloc,nomFonction,var,tempExp);
  cfg.current_bb->add_IRInstr(call);
  return var;
}

string ValCaseTab::buildIR(CFG & cfg)
{
  cout << "-= Building IR ValCaseTab : " << getNomVariable() <<"=-" << endl;
  string index = expression->buildIR(cfg);
  string temp = cfg.create_new_tempvar(Type::Int32);
  IRInstr_rmem* instr = new IRInstr_rmem(cfg.current_bb, Type::Int32, cfg.current_bloc, temp, cfg.get_var_index(nom, cfg.current_bloc));
  cfg.current_bb->add_IRInstr(instr);
  return temp;

}
