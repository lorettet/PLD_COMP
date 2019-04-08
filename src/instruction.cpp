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

//
// WORK IN PROGRESS
//
/*
string InstructionIF::buildIR(CFG & cfg){
  test→buildIR(cfg); //returns a variable name but we don’t use it
  testBB = cfg→currentBB;
  thenBB = new BasicBlock(cfg, trueCode); //this constructor also generates the code
  elseBB = new BasicBlock(cfg, falseCode);
  afterIfBB = new BasicBlock(cfg); //constructor of an empty basic block
  afterIfBB→exitTrue = testBB→exitTrue; //pointer stitching
  afterIfBB→exitFalse = testBB→exitFalse; //pointer stitching
  testBB→exitTrue = thenBB; //pointer stitching
  testBB→exitFalse = elseBB; //pointer stitching
  thenBB→exitTrue = afterIfBB; //pointer stitching
  thenBB→exitFalse = NULL; //unconditional exit
  elseBB→exitTrue = afterIfBB; //pointer stitching
  elseBB→exitFalse = NULL; //unconditional exit
  cfg→currentBB = afterIfBB;
}
*/