#include "IR.h"
#include "symboles.h"


CFG::CFG(Fonction * ast_) : ast(ast_)
{
  BasicBlock firstBB = new BasicBlock(this,"_block");
  add_bb(firstBB);
  current_bb = firstBB;
  for(auto dec : ast->declarations)
  {
    add_to_symbol_table(dec->getNomVariable());
    dec->buildIR(*this);
  }
}

int CFG::get_var_index(string name)
{
  return SymbolIndex[name];
}

Type CFG::get_var_type(string name)
{
  return SymbolType[name];
}

void CFG::add_bb(BasicBlock* bb)
{
  bbs.push_back(bb);
}

void CFG::gen_asm(ASMWriter asmb)
{

}

string CFG::new_BB_name()
{
  return "block"+to_string(bbs.size());
}

void CFG::add_to_symbol_table(string name, Type t)
{
  nextFreeSymbolIndex -= t.size;
  SymbolIndex[name] = nextFreeSymbolIndex;
  SymbolType[name] = t;
}

string CFG::create_new_tempvar(Type t)
{
  add_to_symbol_table("!temp"+to_string(lastTempVar),t);
}

void CFG::gen_asm(ASMWriter & asmb)
{
  gen_asm_prologue(asmb);
  for(auto bb : bbs)
  {
    bb->gen_asm(asmb);
  }
  gen_asm_epilogue(asmb);
}

void CFG::buildIR()
{
  for(auto instr : ast->instructions)
  {
    instr->buildIR(*this);
  }
}

void gen_asm_prologue(ASMWriter & asmb)
{
  asmb.addPrologue();
}

void gen_asm_epilogue(ASMWriter & asmb)
{
  asmb.addEpilogue();
}

BasicBlock::BasicBlock(CFG* cfg, string entry_label) : cfg(cfg_), label(entry_label)
{
}

BasicBlock::~BasicBlock()
{
  for(auto instr : instrs)
  {
    delete instr;
  }
}

void BasicBlock::addInstr(IRInstr instr)
{
  instrs.push_back(instr);
}

void BasicBlock::gen_asm(ASMWriter & asmb)
{
  for(auto instr : instrs)
  {
    instr->gen_asm(asmb);
  }
}

IRInstr::IRInstr(BasicBlock* bb_, Operation op, Type t, vector<string> params) : bb(bb_), op(op_), t(t_), params(params_)
{

}
