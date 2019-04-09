#include "symboles.h"
#include <sstream>

string Affectation::buildIR(CFG & cfg)
{
  cout << "-= Building IR Affect =-" << endl;
  cout << "Getting right" << endl;
  string right = expression->buildIR(cfg);
  cout << "Getting left" << endl;
  string left = variable->buildIR(cfg);
  IRInstr_wmem* instr = new IRInstr_wmem(cfg.current_bb,Type::Int32,cfg.current_bloc,cfg.get_var_index(left,cfg.current_bloc),right);
  cout << "Adding IR Affec" << endl;
  cfg.current_bb->add_IRInstr(instr);
  return right;
}

string Return::buildIR(CFG & cfg)
{
  cout << "-= Building IR Return =-" << endl;
  cout << "Getting right" << endl;
  string var = expression->buildIR(cfg);
  IRInstr_ret* instr = new IRInstr_ret(cfg.current_bb,Type::Int32,cfg.current_bloc,var);
  cout << "Adding IR Return" << endl;
  cfg.current_bb->add_IRInstr(instr);
  cout << "Binding ("<< cfg.current_bb->label << ") exit_true to return bloc : " << cfg.bbs[1]->label << endl;
  cfg.current_bb->exit_true = cfg.bbs[1];
  return "end";
}

string ExpressionSeule::buildIR(CFG & cfg)
{
  cout << "-= Building IR Exp Seule =-" << endl;
  //string var = expression->buildIR(cfg);
  //TODO
  return "";
}

string InstrIF::buildIR(CFG & cfg)
{
  cout << "-= Building IR InstrIF =-" << endl;
  return ifStatement->buildIR(cfg);
}

string IfInstr::buildIR(CFG & cfg){
  cout << "-= Building IR IfInstr =-" << endl;
  cfg.current_bb->testResultVar = testExpression->buildIR(cfg);
  BasicBlock* backupCurrentBB = cfg.current_bb;
  BasicBlock* thenBB = new BasicBlock(&cfg, cfg.new_BB_name());
  cfg.add_bb(thenBB);
  cfg.current_bb = thenBB;
  string thenRet = instruction->buildIR(cfg);

  backupCurrentBB->exit_true = thenBB; // on bind le bloc de base au bloc then

  if(elseStatement == nullptr) // si if simple
  {
    BasicBlock* afterIfBB = new BasicBlock(&cfg,cfg.new_BB_name());
    cfg.add_bb(afterIfBB);
    backupCurrentBB->exit_false = afterIfBB; // on bind le bloc de base au bloc after
    if(thenRet == "end")
    {
      cout << "Then contains a return -> exit_true already bind" << endl;
    }
    else
    {
      if(thenBB->exit_true == nullptr) // if not already modified by antother if
      {
        thenBB->exit_true = afterIfBB; // on bind de bloc then au bloc after
      }
    }
    cfg.current_bb = afterIfBB;
  }
  else // if contains else
  {
    cfg.current_bb = backupCurrentBB;
    elseStatement->buildIR(cfg);
  }
  return "";
}


string ElseSimple::buildIR(CFG & cfg)
{
  BasicBlock* elseBB = new BasicBlock(&cfg, cfg.new_BB_name());
  cfg.add_bb(elseBB);
  BasicBlock* backupCurrentBB = cfg.current_bb;
  backupCurrentBB->exit_false = elseBB; // on bind le bloc de base au bloc else
  cfg.current_bb = elseBB;
  string elseRet = instruction->buildIR(cfg);
  BasicBlock* afterElseBB = new BasicBlock(&cfg, cfg.new_BB_name());
  cfg.add_bb(afterElseBB);
  BasicBlock* thenBB = backupCurrentBB->exit_true;
  thenBB->exit_true = afterElseBB;
  if(elseRet == "end")
  {
    cout << "Else contains a return -> exit already bind" << endl;
  }
  else
  {
    elseBB->exit_true = afterElseBB; // on bind le bloc else au bloc after
  }
  cfg.current_bb = afterElseBB;
  return "";
}

string ElseIf::buildIR(CFG & cfg)
{
  return ifStatement->buildIR(cfg);
}

string Bloc::buildIR(CFG & cfg)
{
  cout << "-= Building IR Bloc =-" << endl;
  parent = cfg.current_bloc;
  cout << "Parent is " << parent << endl;
  cout << "Current is " << this << endl;
  cfg.current_bloc = this;
  stringstream ss;
  ss << this;
  string pointerString = ss.str();
  for(vector<Declaration*>::iterator pObj = declarations.begin(); pObj != declarations.end(); ++pObj)
  {
    cfg.add_to_symbol_table((*pObj)->getNomVariable()+pointerString, Type::Int32);
    (*pObj)->buildIR(cfg);
  }
  string ret = "";
  for(vector<Instruction*>::iterator pObj = instructions.begin(); pObj != instructions.end(); ++pObj)
  {
    cout << "Building instr" << endl;
    cout << typeid(**pObj).name() << endl;
    ret = (*pObj)->buildIR(cfg);
    if(ret == "end")
    {
      cout << "-- Return reached --"<< endl << "not evaluating next basic block instr" << endl; ;
      break; // fin de bloc
    }
    cout << "instr done" << endl;
  }
  cout << "-= Exiting IR Bloc =-" << endl;
  cout << "New current bloc is " << parent << endl;
  cfg.current_bloc = parent;
  return ret;
}

string Bloc::hasLocalVariable(string var)
{
  cout << "trying to get " << var << " in " << this << endl;
  if(variables.find(var) != variables.end())
  {
    cout << "Found localy!" << endl;
    stringstream ss;
    ss << this;
    return ss.str();
  }
  if(parent)
  {
    cout << "searching in parent" << endl;
    return parent->hasLocalVariable(var);
  }
  return "";
}
