
#include "IR.h"
#include "symboles.h"
#include <sstream>

CFG::CFG(Fonction * ast_) : ast(ast_)
{
  cout << "Creating CFG" << endl;
  current_bloc = nullptr;
}

CFG::~CFG()
{
  for(auto bb : bbs)
  {
    delete bb;
  }
}

int CFG::get_var_index(string name,Bloc* context)
{
  cout << "===== getting " << name << endl;
  if(name.at(0) == '!')
  {
    return SymbolIndex[name];
  }
  string res = context->hasLocalVariable(name);
  if(res != "")
    return SymbolIndex[name+res];
  throw exception();
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
  return ast->nom+"_bblock"+to_string(bbs.size());
}

void CFG::add_to_symbol_table(string name, Type t)
{
  cout << "Adding " << name << " at " <<  nextFreeSymbolIndex-t << endl;
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
    if(bb->exit_true && !bb->exit_false)
    {
      asmb.addJmp(bb->exit_true->label);
    }
  }
  gen_asm_epilogue(asmb);
}

void CFG::buildIR()
{
  cout << "=== Building IR CFG for function "<< ast->nom << " ===" << endl;
  string nomBloc = ast->nom+"_main_bbloc";
  BasicBlock* mainBB = new BasicBlock(this,nomBloc);
  add_bb(mainBB);
  current_bb = mainBB;
  BasicBlock* retBB = new BasicBlock(this,ast->nom+"_ret_bbloc");
  add_bb(retBB);
  mainBB->exit_true = retBB;
  ast->buildIR(*this);
}

void CFG::gen_asm_prologue(ASMWriter & asmb)
{
  asmb.initFunction(ast->nom);
  asmb.addPrologue(getStackSize(),ast->params->getNbParams());
}

void CFG::gen_asm_epilogue(ASMWriter & asmb)
{
  asmb.addEpilogue();
}

int CFG::getStackSize()
{
  int res = 0;
  for(auto p : SymbolType)
  {
    res += p.second;
  }
  return res;
}

BasicBlock::BasicBlock(CFG* cfg_, string entry_label) : cfg(cfg_), label(entry_label)
{
  exit_true = nullptr;
  exit_false = nullptr;
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
  asmb.addLabel(label);
  for(auto instr : instrs)
  {
    instr->gen_asm(asmb);
  }
}

IRInstr::IRInstr(BasicBlock* bb_, Type t_, Bloc* b_) : bb(bb_), t(t_), context(b_)
{
}

IRInstr_ldconst::IRInstr_ldconst(BasicBlock* bb_, Type t_, Bloc* b_, string dest_, int c_) : IRInstr(bb_,t_,b_), dest(dest_), c(c_)
{
}

void IRInstr_ldconst::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM ldconst" << endl;
    int addrDest = bb->cfg->get_var_index(dest, context);
    int val = c;

    asmb.addAffectationInt(addrDest, val, t);
}

IRInstr_add::IRInstr_add(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_add::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM add" << endl;
    int addrRes = bb->cfg->get_var_index(dest, context);
    int addrx = bb->cfg->get_var_index(x, context);
    int addry = bb->cfg->get_var_index(y, context);

    asmb.addAddition(addrRes, addrx, addry, t);
}

IRInstr_sub::IRInstr_sub(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_sub::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM sub" << endl;
    int addrRes = bb->cfg->get_var_index(dest, context);
    int addrx = bb->cfg->get_var_index(x, context);
    int addry = bb->cfg->get_var_index(y, context);

    asmb.addSubstraction(addrRes, addrx, addry, t);
}

IRInstr_mul::IRInstr_mul(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

IRInstr_div::IRInstr_div(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_mul::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM mul" << endl;
    int addrRes = bb->cfg->get_var_index(dest, context);
    int addrx = bb->cfg->get_var_index(x, context);
    int addry = bb->cfg->get_var_index(y, context);

    asmb.addMultiplication(addrRes, addrx, addry, t);
}


IRInstr_div::IRInstr_div(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_div::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM div" << endl;
    int addrRes = bb->cfg->get_var_index(dest, context);
    int addrx = bb->cfg->get_var_index(x, context);
    int addry = bb->cfg->get_var_index(y, context);

    asmb.addDivision(addrRes, addrx, addry, t);
}

IRInstr_cmp_eq::IRInstr_cmp_eq(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_eq::gen_asm(ASMWriter& asmb)
{
    int addrRes = bb->cfg->get_var_index(dest, context);
    int addrx = bb->cfg->get_var_index(x, context);
    int addry = bb->cfg->get_var_index(y, context);

    asmb.addComparison(addrRes, addrx, addry, ASMWriter::cmp::eq, t);
}

IRInstr_cmp_lt::IRInstr_cmp_lt(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_lt::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_cmp_le::IRInstr_cmp_le(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y) : IRInstr(bb_,t,b_),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_le::gen_asm(ASMWriter& asmb)
{
    // A FAIRE
}

IRInstr_call::IRInstr_call(BasicBlock* bb_, Type t, Bloc* b_, string label, string dest, vector<string> params) : IRInstr(bb_,t,b_),label(label),dest(dest),params(params)
{}

void IRInstr_call::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM call" << endl;
    int addrDest = bb->cfg->get_var_index(dest, context);
    vector<int> addrs;
    for(auto p : params)
    {
      addrs.push_back(bb->cfg->get_var_index(p, context));
    }
    asmb.addCall(label, addrDest, t, addrs);
}

IRInstr_rmem::IRInstr_rmem(BasicBlock* bb_, Type t,Bloc* b_, string dest, int addr) : IRInstr(bb_,t,b_),dest(dest),addr(addr)
{}

void IRInstr_rmem::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM rmem" << endl;
    int addrDest = bb->cfg->get_var_index(dest, context);
    asmb.addReadMem(addrDest, addr, t);
}

IRInstr_wmem::IRInstr_wmem(BasicBlock* bb_, Type t, Bloc* b_, int addr, string var) : IRInstr(bb_,t,b_),addr(addr),var(var)
{
}

void IRInstr_wmem::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM wmem" << endl;
    int addrVar = bb->cfg->get_var_index(var, context);
    asmb.addWriteMem(addr, addrVar, t);
}

IRInstr_ret::IRInstr_ret(BasicBlock* bb_, Type t, Bloc* b_, string var) : IRInstr(bb_,t,b_),var(var)
{}

void IRInstr_ret::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM ret" << endl;
    cout << "----------------------" << context << endl;
    int addrVar = bb->cfg->get_var_index(var, context);
    asmb.addReturnVar(addrVar,bb->cfg->ast->nom,t);
}

IRInstr_neg::IRInstr_neg(BasicBlock* bb_, Type t,Bloc* b_, string var) : IRInstr(bb_,t,b_),var(var)
{}

void IRInstr_neg::gen_asm(ASMWriter& asmb)
{
    cout << "gen ASM neg" << endl;
    int addrVar = bb->cfg->get_var_index(var, context);
    asmb.addNeg(addrVar,t);
}
