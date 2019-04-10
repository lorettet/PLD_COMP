#ifndef IR_H
#define IR_H

#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>

#include "type.h"
#include "ASMWriter.h"
class Bloc;
class BasicBlock;
class CFG;
class Fonction;
class IRInstr;


/**  The class for a basic block */

/* A few important comments.
	 IRInstr has no jump instructions:
	 assembly jumps are generated as follows in BasicBlock::gen_asm():
     1/ a cmp_* comparison instructions, if it is the last instruction of its block,
       generates an actual assembly comparison followed by a conditional jump to the exit_false branch
			 If it is not the last instruction of its block, it behaves as an arithmetic two-operand instruction (add or mult)
		 2/ BasicBlock::gen_asm() first calls IRInstr::gen_asm() on all its instructions, and then
		    if  exit_true  is a  nullptr, it generates the epilogue
				if  exit_false is not a nullptr, and the last instruction is not a cmp, it generates two conditional branches based on the value of the last variable assigned
        otherwise it generates an unconditional jmp to the exit_true branch
*/

class BasicBlock {
 public:
	BasicBlock(CFG* cfg_, string entry_label);
  virtual ~BasicBlock();
	void gen_asm(ASMWriter & asmb); /**< x86 assembly code generation for this basic block (very simple) */

	void add_IRInstr(IRInstr* instr);

	// No encapsulation whatsoever here. Feel free to do better.
	BasicBlock* exit_true;  /**< pointer to the next basic block, true branch. If nullptr, return from procedure */
	BasicBlock* exit_false; /**< pointer to the next basic block, false branch. If null_ptr, the basic block ends with an unconditional jump */
	string label; /**< label of the BB, also will be the label in the generated code */
	CFG* cfg; /** < the CFG where this block belongs */
	vector<IRInstr*> instrs; /** < the instructions themselves. */
    string testResultVar;
 protected:


};




/** The class for the control flow graph, also includes the symbol table */

/* A few important comments:
	 The entry block is the one with the same label as the AST function name.
	   (it could be the first of bbs, or it could be defined by an attribute value)
	 The exit block is the one with both exit pointers equal to nullptr.
     (again it could be identified in a more explicit way)

 */
class CFG {
 public:
	CFG(Fonction* ast_);
  virtual ~CFG();

	Fonction* ast; /**< The AST this CFG comes from */

  void buildIR();

	void add_bb(BasicBlock* bb);

	// x86 code generation: could be encapsulated in a processor class in a retargetable compiler
	void gen_asm(ASMWriter & asmb);
	//string IR_reg_to_asm(string reg); /**< helper method: inputs a IR reg or input variable, returns e.g. "-24(%rbp)" for the proper value of 24 */
	void gen_asm_prologue(ASMWriter & asmb);
	void gen_asm_epilogue(ASMWriter & asmb);

	// symbol table methods
	void add_to_symbol_table(string name, Type t);
	string create_new_tempvar(Type t);
	int get_var_index(string name, Bloc* context);
	Type get_var_type(string name);

	// basic block management
	string new_BB_name();
	BasicBlock* current_bb;
  Bloc* current_bloc;
  	vector <BasicBlock*> bbs; /**< all the basic blocks of this CFG*/

  int getStackSize();


 protected:
	map <string, Type> SymbolType; /**< part of the symbol table  */
	map <string, int> SymbolIndex; /**< part of the symbol table  */
	int nextFreeSymbolIndex = 0; /**< to allocate new symbols in the symbol table */
  int lastTempVar = 0;

};


class IRInstr {

    public:
        IRInstr(BasicBlock* bb_, Type t_, Bloc* b_);
        virtual ~IRInstr(){}
        virtual void gen_asm(ASMWriter& asmb) = 0; /**< x86 assembly code generation for this IR instruction */

    protected:
        BasicBlock* bb; /**< The BB this instruction belongs to, which provides a pointer to the CFG this instruction belong to */
        Type t;
        Bloc* context;
};

class IRInstr_ldconst : public IRInstr {

    public:
        IRInstr_ldconst(BasicBlock* bb_, Type t_, Bloc* b_, string dest_, int c_);
        virtual ~IRInstr_ldconst(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        int c;
};

class IRInstr_add : public IRInstr {

    public:
        IRInstr_add(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_add(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_sub : public IRInstr {

    public:
        IRInstr_sub(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_sub(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_mul : public IRInstr {

    public:
        IRInstr_mul(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_mul(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_div : public IRInstr {

    public:
        IRInstr_div(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_div(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_eq : public IRInstr {

    public:
        IRInstr_cmp_eq(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_eq(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_gt : public IRInstr {

    public:
        IRInstr_cmp_gt(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_gt(){}
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_ge : public IRInstr {

    public:
        IRInstr_cmp_ge(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_ge(){}
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_neq : public IRInstr {

    public:
        IRInstr_cmp_neq(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_neq(){}
        void gen_asm(ASMWriter& asmw);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_lt : public IRInstr {

    public:
        IRInstr_cmp_lt(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_lt(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_cmp_le : public IRInstr {

    public:
        IRInstr_cmp_le(BasicBlock* bb_, Type t, Bloc* b_, string dest, string x, string y);
        virtual ~IRInstr_cmp_le(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        string x;
        string y;
};

class IRInstr_call : public IRInstr {

    public:
        IRInstr_call(BasicBlock* bb_, Type t, Bloc* b_, string label, string dest, vector<string> params);
        virtual ~IRInstr_call(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string label;
        string dest;
        vector<string> params;
};

class IRInstr_rmem : public IRInstr {

    public:
        IRInstr_rmem(BasicBlock* bb_, Type t, Bloc* b_, string dest, int addr);
        virtual ~IRInstr_rmem(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string dest;
        int addr;
};

class IRInstr_wmem : public IRInstr {

    public:
        IRInstr_wmem(BasicBlock* bb_, Type t, Bloc* b_, int addr, string var);
        virtual ~IRInstr_wmem(){}
        void gen_asm(ASMWriter& asmb);

    private:
        int addr;
        string var;
};

class IRInstr_ret : public IRInstr {

    public:
        IRInstr_ret(BasicBlock* bb_, Type t, Bloc* b_, string var);
        virtual ~IRInstr_ret(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string var;
};

class IRInstr_neg : public IRInstr {

    public:
        IRInstr_neg(BasicBlock* bb_, Type t, Bloc* b_, string var);
        virtual ~IRInstr_neg(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string var;
};

class IRInstr_not : public IRInstr {

    public:
        IRInstr_not(BasicBlock* bb_, Type t, Bloc* b_, string var);
        virtual ~IRInstr_not(){}
        void gen_asm(ASMWriter& asmb);

    private:
        string var;
};

#endif
