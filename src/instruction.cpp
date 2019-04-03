#include "symboles.h"

string Affectation::buildIR(CFG & cfg)
{
  cout << "Building IR Affect" << endl;
  cout << "Getting right" << endl;
  string right = expression->buildIR(cfg);
  cout << "Getting left" << endl;
  string left = variable->buildIR(cfg);
  IRInstr_wmem* instr = new IRInstr_wmem(cfg.current_bb,Type::Int32,cfg.get_var_index(left),right);
  cout << "Adding IR Affec" << endl;
  cfg.current_bb->add_IRInstr(instr);
  return right;
}

string Return::buildIR(CFG & cfg)
{
  cout << "Building IR Return" << endl;
  cout << "Getting right" << endl;
  string var = expression->buildIR(cfg);
  IRInstr_ret* instr = new IRInstr_ret(cfg.current_bb,Type::Int32,var);
  cout << "Adding IR Return" << endl;
  cfg.current_bb->add_IRInstr(instr);
  return var;
}

string ExpressionSeule::buildIR(CFG & cfg)
{
  cout << "Building IR Exp Seule" << endl;
  //string var = expression->buildIR(cfg);
  //TODO
  return "";
}

string Bloc::buildIR(CFG & cfg)
{
  cout << "-= Building IR Bloc =-" << endl;
  string nomBloc = cfg.new_BB_name();
  BasicBlock* BB = new BasicBlock(&cfg,nomBloc);
  cfg.add_bb(BB);
  cfg.current_bb = BB;
  for(vector<Declaration*>::iterator pObj = declarations.begin(); pObj != declarations.end(); ++pObj)
  {
    cfg.add_to_symbol_table((*pObj)->getNomVariable(), Type::Int32);
    (*pObj)->buildIR(cfg);
  }
  for(vector<Instruction*>::iterator pObj = instructions.begin(); pObj != instructions.end(); ++pObj)
  {
    cout << "Building instr" << endl;
    cout << typeid(**pObj).name() << endl;
    (*pObj)->buildIR(cfg);
    cout << "instr done" << endl;
  }
  return "";
}
