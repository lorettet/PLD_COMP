#include "symboles.h"

string TestExprCompar::buildIR(CFG & cfg)
{
  cout << "-= Building IR TestExpr =-" << endl;
  string var1 = expression1->buildIR(cfg);
  string var2 = expression2->buildIR(cfg);
  string res = cfg.create_new_tempvar(Type::Int32);
  IRInstr* instr;
  switch(signe)
  {
    case EGAL:
      cout << "EGAL" << endl;
      instr = new IRInstr_cmp_eq(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
    case DIFF:
      cout << "DIFF" << endl;
      instr = new IRInstr_cmp_neq(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
    case SUPSTRICT:
      cout << "SUPSTRICT" << endl;
      instr = new IRInstr_cmp_gt(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
    case SUPEGAL:
      cout << "SUPEGAL" << endl;
      instr = new IRInstr_cmp_ge(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
    case INFSTRICT:
      cout << "INFSTRICT" << endl;
      instr = new IRInstr_cmp_lt(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
    case INFEGAL:
      cout << "INFEGAL" << endl;
      instr = new IRInstr_cmp_le(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var1, var2);
      cfg.current_bb->add_IRInstr(instr);
      return res;
  }
}

string TestExpressionSimple::buildIR(CFG & cfg){
	cout << "-= Building IR TestExpressionSimple =-" << endl;
	string res = cfg.create_new_tempvar(Type::Int32);
	string var = expression->buildIR(cfg);
	string temp_var = cfg.create_new_tempvar(Type::Int32);
	IRInstr* instr_temp_var = new IRInstr_ldconst(cfg.current_bb, Type::Int32, cfg.current_bloc, temp_var, 0);
	IRInstr* instr_test_neq = new IRInstr_cmp_neq(cfg.current_bb, Type::Int32, cfg.current_bloc, res, var, temp_var);
	cfg.current_bb->add_IRInstr(instr_temp_var);
    cfg.current_bb->add_IRInstr(instr_test_neq);
	return res;
}
