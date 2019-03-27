#pragma once

#include <map>
#include <vector>
#include <string>
#include "ASMWriter.h"

using namespace std;

class Expression {
	public:
		Expression(){}
		virtual ~Expression(){}
};

class Addition : public Expression {
	public:
		Addition(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Addition(){}
	
	protected:
		Expression* exp1;
		Expression* exp2;
};

class Soustraction : public Expression {
	public:
		Soustraction(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Soustraction(){}
	
	protected:
		Expression* exp1;
		Expression* exp2;
};

class Multiplication : public Expression {
	public:
		Multiplication(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Multiplication(){}
	
	protected:
		Expression* exp1;
		Expression* exp2;
};

class Division : public Expression {
	public:
		Division(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Division(){}
	
	protected:
		Expression* exp1;
		Expression* exp2;
};

		
class Parenthese : public Expression {
	public:
		Parenthese(Expression* e) : exp(e) {}
		~Parenthese(){}
	
	protected:
		Expression* exp;
};

class Valeur : public Expression {
	public:
		Valeur() { }
		virtual ~Valeur(){}
		int virtual getValue(){}
};

class Int : public Valeur{
	public:
		Int(int val) : valeur(val) { }
		~Int() { }
		int getValue() {return valeur;}
	protected:
		int valeur;
};

class Variable : public Valeur {
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
		void virtual getASM(ASMWriter & asmb, map<string,int> var){}
};

class Affectation : public Instruction {
	public:
		Affectation(Variable* var, Expression* expr) : variable(var), expression(expr) { }
		~Affectation() { }
		void getASM(ASMWriter & asmb, map<string,int> var);
	protected:
		Variable* variable;
		Expression* expression;
};

class Return : public Instruction {
	public:
		Return(Expression* expr) : expression(expr) { }
		~Return() { }
		void getASM(ASMWriter & asmb, map<string,int> var);
	protected:
		Expression* expression;
};

class Declaration {
	public:
		~Declaration();
		string getNomVariable();
		void virtual getASM(ASMWriter & asmb, map<string,int> var){};
	protected:
		Variable* variable;
};

class DeclarationSimple : public Declaration {
	public:
		DeclarationSimple(Variable* v) { variable = v; }
		void getASM(ASMWriter & asmb, map<string,int> var);
};

class DeclarationAvecAffectation : public Declaration {
	public:
		DeclarationAvecAffectation(Variable* v, Expression* expr): expression(expr) { variable = v; }
		void getASM(ASMWriter & asmb, map<string,int> var);
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
