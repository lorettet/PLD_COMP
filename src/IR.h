#ifndef IR_H
#define IR_H

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

#include "type.h"
#include "symboles.h"
class BasicBlock;
class CFG;
class DefFonction;

class IRInstr {
 
    public:
        /**  constructor */
        IRInstr(BasicBlock* bb_, Type t);

        /** Actual code generation */
        virtual void gen_asm(ASMWriter& asmw) = 0; /**< x86 assembly code generation for this IR instruction */
	
    protected:
        BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
        Type t;
};

class IRInstr_ldconst : public IRInstr {

    public:
        IRInstr_ldconst(BasicBlock* bb_, Type t, string dest, string c);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string c;
}

class IRInstr_add : public IRInstr {

    public:
        IRInstr_add(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_sub : public IRInstr {

    public:
        IRInstr_sub(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_mul : public IRInstr {

    public:
        IRInstr_mul(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_cmp_eq : public IRInstr {

    public:
        IRInstr_cmp_eq(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_cmp_lt : public IRInstr {

    public:
        IRInstr_cmp_lt(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_cmp_le : public IRInstr {

    public:
        IRInstr_cmp_le(BasicBlock* bb_, Type t, string dest, string x, string y);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
}

class IRInstr_call : public IRInstr {

    public:
        IRInstr_call(BasicBlock* bb_, Type t, string label, string dest, vector<string> params);
        void gen_asm(ASMWriter& asmw);

    private:
        string label;
        string dest;
        vector<string> params;
}

class IRInstr_rmem : public IRInstr {

    public:
        IRInstr_rmem(BasicBlock* bb_, Type t, string dest, int addr);
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        int addr;
}

class IRInstr_wmem : public IRInstr {

    public:
        IRInstr_wmem(BasicBlock* bb_, Type t, int addr, string var);
        void gen_asm(ASMWriter& asmw);

    private:
        int addr;
        string var;
}


// class BasicBlock {
//  public:
// 	BasicBlock(CFG* cfg, string entry_label);
// 	void gen_asm(ostream &o); /**< x86 assembly code generation for this basic block (very simple) */

// 	void add_IRInstr(IRInstr::Operation op, Type t, vector<string> params);

// 	// No encapsulation whatsoever here. Feel free to do better.
// 	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */ 
// 	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
// 	string label; /**< label of the BB, also will be the label in the generated code */
// 	CFG* cfg; /** < the CFG where this block belongs */
// 	vector<IRInstr*> instrs; /** < the instructions themselves. */
//  protected:

 
// };

// class CFG {
//  public:
// 	CFG(DefFonction* ast);

// 	DefFonction* ast; /**< The AST this CFG comes from */
	
// 	void add_bb(BasicBlock* bb); 

// 	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
// 	void gen_asm(ostream& o);
// 	string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
// 	void gen_asm_prologue(ostream& o);
// 	void gen_asm_epilogue(ostream& o);

// 	// symbol table methods
// 	void add_to_symbol_table(string name, Type t);
// 	string create_new_tempvar(Type t);
// 	int get_var_index(string name);
// 	Type get_var_type(string name);

// 	// basic block management
// 	string new_BB_name();
// 	BasicBlock* current_bb;

//  protected:
// 	map <string, Type> SymbolType; /**< part of the symbol table  */
// 	map <string, int> SymbolIndex; /**< part of the symbol table  */
// 	int nextFreeSymbolIndex; /**< to allocate new symbols in the symbol table */
// 	int nextBBnumber; /**< just for naming */
	
// 	vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/
// };





#endif