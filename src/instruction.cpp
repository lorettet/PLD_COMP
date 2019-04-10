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

/*string InstrIF::buildIR(CFG & cfg)
{
  cout << "-= Building IR InstrIF =-" << endl;
  return ifStatement->buildIR(cfg);
}*/

string IfInstr::buildIR(CFG & cfg){
  cout << "-= Building IR IfInstr =-" << endl;
  cfg.current_bb->testResultVar = testExpression->buildIR(cfg);
  BasicBlock* backupCurrentBB = cfg.current_bb;
  BasicBlock* thenBB = new BasicBlock(&cfg, cfg.new_BB_name());
  cfg.add_bb(thenBB);

  BasicBlock* afterIfBB = new BasicBlock(&cfg,cfg.new_BB_name());
  cfg.add_bb(afterIfBB);

  if(elseStatement == nullptr) // si if simple
  {
    backupCurrentBB->exit_false = afterIfBB; // on bind le bloc de base au bloc after
    afterIfBB->exit_true = backupCurrentBB->exit_true; // on bind le bloc after if a l'ancien exit true du bloc de base
    backupCurrentBB->exit_true = thenBB; // on bind le bloc de base au bloc then
    thenBB->exit_true = afterIfBB; // on bind le bloc then au bloc after
    cfg.current_bb = afterIfBB;
  }
  else // if contains else
  {
    backupCurrentBB->exit_false = afterIfBB; // on bind le bloc de base au bloc after
    cout << afterIfBB->label << " T-> " << backupCurrentBB->exit_true->label << endl;
    afterIfBB->exit_true = backupCurrentBB->exit_true; // on bind le bloc after if a l'ancien exit true du bloc de base
    cout << backupCurrentBB->label << " T-> " << thenBB->label << endl;
    backupCurrentBB->exit_true = thenBB; // on bind le bloc de base au bloc then
    cout << thenBB->label << " T-> " << afterIfBB->label << endl;
    thenBB->exit_true = afterIfBB; // on bind le bloc then au bloc after
    cfg.current_bb = backupCurrentBB;
    elseStatement->buildIR(cfg);
  }

  cfg.current_bb = thenBB;
  string thenRet = instruction->buildIR(cfg);
  if(thenRet == "end")
  {
    cout << "Then contains a return -> exit_true re bind" << endl;
  }



  cfg.current_bb = afterIfBB;
  return "";
}


string ElseSimple::buildIR(CFG & cfg)
{
  BasicBlock* elseBB = new BasicBlock(&cfg, cfg.new_BB_name());
  cfg.add_bb(elseBB);
  BasicBlock* backupCurrentBB = cfg.current_bb;
  cout << backupCurrentBB->label << " F-> " << elseBB->label << endl;
  backupCurrentBB->exit_false = elseBB; // on bind le bloc de base au bloc else
  BasicBlock* afterElseBB = backupCurrentBB->exit_false;
  cout << elseBB->label << " T-> " << afterElseBB->label << endl;
  elseBB->exit_true = afterElseBB; // on bind le bloc else au bloc after



  cfg.current_bb = elseBB;
  string elseRet = instruction->buildIR(cfg);
  if(elseRet == "end")
  {
    cout << "Else contains a return -> exit_true re bind" << endl;
  }
  else
  {
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
