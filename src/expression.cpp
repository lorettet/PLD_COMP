#include "symboles.h"
#include <string>
#include <iostream>
using namespace std;

string Addition::buildIR(CFG & cfg)
{
  cout << "-= Building IR Add =-" << endl;
  cout << "Getting exp1" << endl;
  string var1 = exp1->buildIR(cfg);
  cout << "Getting exp2" << endl;
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_add* add = new IRInstr_add(cfg.current_bb,Type::Int32,var,var1,var2);
  cout << "-= Adding IR Add =-" << endl;
  cfg.current_bb->add_IRInstr(add);
  return var;
}

string Soustraction::buildIR(CFG & cfg)
{
  cout << "-= Building IR Sub =-" << endl;
  cout << "Getting exp1" << endl;
  string var1 = exp1->buildIR(cfg);
  cout << "Getting exp2" << endl;
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_sub* sub = new IRInstr_sub(cfg.current_bb,Type::Int32,var,var1,var2);
  cout << "-= Adding IR Sub =-" << endl;
  cfg.current_bb->add_IRInstr(sub);
  return var;
}

string Multiplication::buildIR(CFG & cfg)
{
  cout << "-= Building IR Mul =-" << endl;
  cout << "Getting exp1" << endl;
  string var1 = exp1->buildIR(cfg);
  cout << "Getting exp2" << endl;
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_mul* mul = new IRInstr_mul(cfg.current_bb,Type::Int32,var,var1,var2);
  cout << "-= Adding IR Mul =-" << endl;
  cfg.current_bb->add_IRInstr(mul);
  return var;
}

string Division::buildIR(CFG & cfg)
{
  cout << "-= Building IR Div =-" << endl;
  cout << "Getting exp1" << endl;
  string var1 = exp1->buildIR(cfg);
  cout << "Getting exp2" << endl;
  string var2 = exp2->buildIR(cfg);
  string var = cfg.create_new_tempvar(Type::Int32);
  IRInstr_div* div = new IRInstr_div(cfg.current_bb,Type::Int32,var,var1,var2);
  cout << "-= Adding IR Div=- " << endl;
  cfg.current_bb->add_IRInstr(div);
  return var;
}

string ExpressionUnaire::buildIR(CFG & cfg)
{
	
}

string Parenthese::buildIR(CFG & cfg)
{
  cout << "-= Building IR ())=- " << endl;
  cout << "Getting exp" << endl;
  string var = exp->buildIR(cfg);
  cout << "-= temp var is at : " << var << " =-" << endl;
  return var;
}
