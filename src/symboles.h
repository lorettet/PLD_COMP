#pragma once

#include <map>
#include <vector>
#include <string>
#include "ASMWriter.h"

using namespace std;
class Expression {
	public:
		Expression() { }
		virtual ~Expression(){}
		int virtual getValue(){};
};

class Int : public Expression{
	public:
		Int(int val) : valeur(val) { }
		~Int() { }
		int getValue() {return valeur;}
	protected:
		int valeur;
};

class Variable : public Expression {
	public:
		Variable(string s) : nom(s) { }
		~Variable() { }
		string getNomVariable();
	protected:
		string nom;
};

class Instruction {
	public:
		virtual ~Instruction(){}
		void virtual getASM(ASMWriter & asmb){}
};

class Affectation : public Instruction {
	public:
		Affectation(Variable* var, Expression* expr) : variable(var), expression(expr) { }
		~Affectation() { }
		void getASM(ASMWriter & asmb);
	protected:
		Variable* variable;
		Expression* expression;
};

class Return : public Instruction {
	public:
		Return(Expression* expr) : expression(expr) { }
		~Return() { }
		void getASM(ASMWriter & asmb);
	protected:
		Expression* expression;
};

class Declaration {
	public:
		~Declaration();
		string getNomVariable();
		void virtual getASM(ASMWriter & asmb){};
	protected:
		Variable* variable;
};

class DeclarationSimple : public Declaration {
	public:
		DeclarationSimple(Variable* v) { variable = v; }
		void getASM(ASMWriter & asmb);
};

class DeclarationAvecAffectation : public Declaration {
	public:
		DeclarationAvecAffectation(Variable* v, Expression* expr): expression(expr) { variable = v; }
		void getASM(ASMWriter & asmb);
	protected:
		Expression* expression;
};

class Fonction {
	public:
		Fonction() {}
		void ajouterDeclaration(Declaration* dec);
		void ajouterInstruction(Instruction* inst);
		void getASM(ASMWriter & asmb);
	protected:
		vector<Declaration*> declarations;
		vector<Instruction*> instructions;
		map<string,int> variables;
		int index = 0;
};
