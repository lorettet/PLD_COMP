
#include "IR.h"
#include "symboles.h"


CFG::CFG(Fonction * ast_) : ast(ast_)
{
  cout << "Creating CFG" << endl;
  BasicBlock* firstBB = new BasicBlock(this,"_block");
  add_bb(firstBB);
  current_bb = firstBB;
}

CFG::~CFG()
{
  for(auto bb : bbs)
  {
    delete bb;
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

string CFG::new_BB_name()
{
  return "block"+to_string(bbs.size());
}

void CFG::add_to_symbol_table(string name, Type t)
{
  cout << "Adding " << name << nextFreeSymbolIndex-t << endl;
  nextFreeSymbolIndex -= t;
  SymbolIndex[name] = nextFreeSymbolIndex;
  SymbolType[name] = t;
}

string CFG::create_new_tempvar(Type t)
{
  cout << "Creating temp var : !temp" << to_string(lastTempVar) << endl;
  add_to_symbol_table("!temp"+to_string(lastTempVar),t);
  return "!temp"+to_string(lastTempVar++);
}

void CFG::gen_asm(ASMWriter & asmb)
{
  cout << "Starting gen ASM" << endl;
  gen_asm_prologue(asmb);
  for(auto bb : bbs)
  {
    bb->gen_asm(asmb);
  }
  gen_asm_epilogue(asmb);
}

void CFG::buildIR()
{
  cout << "=== Building IR CFG for function "<< ast->nom << " ===" << endl;
  for(vector<Declaration*>::iterator pObj = ast->declarations.begin(); pObj != ast->declarations.end(); ++pObj)
  {
    add_to_symbol_table((*pObj)->getNomVariable(), Type::Int32);
    (*pObj)->buildIR(*this);

  }
  for(vector<Instruction*>::iterator pObj = ast->instructions.begin(); pObj != ast->instructions.end(); ++pObj)
  {
    cout << "Building instr" << endl;
    cout << typeid(**pObj).name() << endl;
    (*pObj)->buildIR(*this);
    cout << "instr done" << endl;
  }
}

void CFG::gen_asm_prologue(ASMWriter & asmb)
{
  asmb.initFunction(ast->nom);
  asmb.addPrologue();
}

void CFG::gen_asm_epilogue(ASMWriter & asmb)
{
  asmb.addEpilogue();
}

BasicBlock::BasicBlock(CFG* cfg_, string entry_label) : cfg(cfg_), label(entry_label)
{
}

BasicBlock::~BasicBlock()
{
  for(auto instr : instrs)
  {
    delete instr;
  }
}

void BasicBlock::add_IRInstr(IRInstr* instr)
{
  instrs.push_back(instr);
}

void BasicBlock::gen_asm(ASMWriter & asmb)
{

  cout << "Starting gen ASM for block : " << label << endl;
  for(auto instr : instrs)
  {
    instr->gen_asm(asmb);
  }
}

IRInstr::IRInstr(BasicBlock* bb_, Type t_) : bb(bb_), t(t_)
{
}

IRInstr_ldconst::IRInstr_ldconst(BasicBlock* bb_, Type t_, string dest_, int c_) : IRInstr(bb_,t_), dest(dest_), c(c_)
{
}

void IRInstr_ldconst::gen_asm(ASMWriter& asmb)
{
    int addrDest = bb->cfg->get_var_index(dest);
    int val = c;

    asmb.addAffectationInt(addrDest, val, t);
}

IRInstr_add::IRInstr_add(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_add::gen_asm(ASMWriter& asmb)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    asmb.addAddition(addrRes, addrx, addry, t);
}

IRInstr_sub::IRInstr_sub(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_sub::gen_asm(ASMWriter& asmb)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    asmb.addSubstraction(addrRes, addrx, addry, t);
}

IRInstr_mul::IRInstr_mul(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

IRInstr_div::IRInstr_div(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_mul::gen_asm(ASMWriter& asmb)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    asmb.addMultiplication(addrRes, addrx, addry, t);
}

void IRInstr_div::gen_asm(ASMWriter& asmb)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    asmb.addDivision(addrRes, addrx, addry, t);
}

IRInstr_cmp_eq::IRInstr_cmp_eq(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_eq::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_cmp_lt::IRInstr_cmp_lt(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_lt::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_cmp_le::IRInstr_cmp_le(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_le::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_call::IRInstr_call(BasicBlock* bb_, Type t, string label, string dest, vector<string> params) : IRInstr(bb_,t),label(label),dest(dest),params(params)
{}

void IRInstr_call::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_rmem::IRInstr_rmem(BasicBlock* bb_, Type t, string dest, int addr) : IRInstr(bb_,t),dest(dest),addr(addr)
{}

void IRInstr_rmem::gen_asm(ASMWriter& asmb)
{
    int addrDest = bb->cfg->get_var_index(dest);

    asmb.addReadMem(addrDest, addr, t);
}

IRInstr_wmem::IRInstr_wmem(BasicBlock* bb_, Type t, int addr, string var) : IRInstr(bb_,t),addr(addr),var(var)
{}

void IRInstr_wmem::gen_asm(ASMWriter& asmb)
{
    int addrVar = bb->cfg->get_var_index(var);

    asmb.addWriteMem(addr, addrVar, t);
}

IRInstr_ret::IRInstr_ret(BasicBlock* bb_, Type t, string var) : IRInstr(bb_,t),var(var)
{}

void IRInstr_ret::gen_asm(ASMWriter& asmb)
{
    int addrVar = bb->cfg->get_var_index(var);

    asmb.addReturnVar(addrVar,t);
}
