#include "ASMWriter.h"
#include "IR.h"
#include "symboles.h"

IRInstr::IRInstr(BasicBlock* bb_, Type t) : bb(bb_), t(t)
{}

IRInstr_ldconst::IRInstr_ldconst(BasicBlock* bb_, Type t, string dest, string c) : IRInstr(bb_,t),dest(dest),c(c)
{}

void IRInstr_ldconst::gen_asm(ASMWriter& asmw)
{
    int addrDest = bb->cfg->get_var_index(dest);
    int val = std::stoi(c);

    addAffectationInt(addrDest, val, t);
}

IRInstr_add::IRInstr_add(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_add::gen_asm(ASMWriter& asmw)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    addAddition(addrRes, addrx, addry, t);
}

IRInstr_sub::IRInstr_sub(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_sub::gen_asm(ASMWriter& asmw)
{
    int addrRes = bb->cfg->get_var_index(dest);
    int addrx = bb->cfg->get_var_index(x);
    int addry = bb->cfg->get_var_index(y);

    addSubstraction(addrRes, addrx, addry, t);
}

IRInstr_mul::IRInstr_mul(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_mul::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_cmp_eq::IRInstr_cmp_eq(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_eq::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_cmp_lt::IRInstr_cmp_lt(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_lt::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_cmp_le::IRInstr_cmp_le(BasicBlock* bb_, Type t, string dest, string x, string y) : IRInstr(bb_,t),dest(dest),x(x),y(y)
{}

void IRInstr_cmp_le::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_call::IRInstr_call(BasicBlock* bb_, Type t, string label, string dest, vector<string> params) : IRInstr(bb_,t),label(label),dest(dest),params(params)
{}

void IRInstr_call::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_rmem::IRInstr_rmem(BasicBlock* bb_, Type t, string dest, int addr) : IRInstr(bb_,t),dest(dest),addr(addr)
{}

void IRInstr_rmem::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}

IRInstr_wmem::IRInstr_wmem(BasicBlock* bb_, Type t, int addr, string var) : IRInstr(bb_,t),addr(addr),var(var)
{}

void IRInstr_wmem::gen_asm(ASMWriter& asmw)
{
    // A FAIRE    
}