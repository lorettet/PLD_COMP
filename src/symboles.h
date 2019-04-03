#pragma once

#include <map>
#include <vector>
#include <string>
#include "ASMWriter.h"
#include "IR.h"

using namespace std;

enum SigneComparaison { INFEGAL, SUPEGAL, EGAL, DIFF, SUPSTRICT, INFSTRICT };
enum SigneLogique { ET, OU };

class Expression {
	public:
		Expression(){}
		virtual ~Expression(){}
		string virtual buildIR(CFG & cfg){}
};

class Addition : public Expression {
	public:
		Addition(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Addition(){}
		string buildIR(CFG & cfg);

	protected:
		Expression* exp1;
		Expression* exp2;
};

class Soustraction : public Expression {
	public:
		Soustraction(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Soustraction(){}
		string buildIR(CFG & cfg);

	protected:
		Expression* exp1;
		Expression* exp2;
};

class Multiplication : public Expression {
	public:
		Multiplication(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Multiplication(){}
		string buildIR(CFG & cfg);

	protected:
		Expression* exp1;
		Expression* exp2;
};

class Division : public Expression {
	public:
		Division(Expression* e1, Expression* e2) : exp1(e1), exp2(e2) {}
		~Division(){}
		string buildIR(CFG & cfg);

	protected:
		Expression* exp1;
		Expression* exp2;
};

class ExpressionUnaire : public Expression {
	public:
	ExpressionUnaire(Expression* e, bool s) : exp(e), isNegative(s) {}
	~ExpressionUnaire(){}
	string buildIR(CFG & cfg);

	protected:
		Expression* exp;
		bool isNegative;
};

class Parenthese : public Expression {
	public:
		Parenthese(Expression* e) : exp(e) {}
		~Parenthese(){}
		string buildIR(CFG & cfg);

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
		string buildIR(CFG & cfg);
	protected:
		int valeur;
};

class Variable : public Valeur {
	public:
		Variable(string s) : nom(s) { }
		~Variable() { }
		string getNomVariable();
		string buildIR(CFG & cfg);
	protected:
		string nom;
};

class Parametre {
	public:
		Parametre(string n, string t) : nom(n), type(t) {}
		virtual ~Parametre(){}

		string nom;
		string type;
};

class ParametresFormels {
	public:
		ParametresFormels(){}
		virtual ~ParametresFormels(){}
		void ajouterParametre(Parametre * p){ listParams.push_back(p);}
		vector<Parametre*> listParams;
};

class ParametresEffectifs {
	public:
		ParametresEffectifs(){}
		virtual ~ParametresEffectifs(){}
		void ajouterExpression(Expression* e){listExpr.push_back(e);}

		vector<Expression*> listExpr;
};

class Appel : public Valeur {
	public:
		Appel(string nomFct, ParametresEffectifs* pe) : nomFonction(nomFct), params(pe) { }
		string buildIR(CFG & cfg);
		virtual ~Appel() { }
	protected:
		string nomFonction;
		ParametresEffectifs* params;
};

class Instruction {
	public:
		virtual ~Instruction(){}
		string virtual buildIR(CFG & cfg){}
};

class ExpressionSeule : public Instruction {
	public:
		ExpressionSeule(Expression* expr) : expression(expr) {}
		virtual ~ExpressionSeule() {}
		string buildIR(CFG & cfg);
	protected:
		Expression* expression;
};

class Affectation : public Instruction {
	public:
		Affectation(Variable* var, Expression* expr) : variable(var), expression(expr) { }
		virtual ~Affectation() { }
		string buildIR(CFG & cfg);
	protected:
		Variable* variable;
		Expression* expression;
};

class InstrIF : public Instruction {
	public:
		InstrIF(){}
};

class IfStatement : public Instruction {
	public:
		IfStatement(){}
		~IfStatement(){}
		string virtual buildIR(CFG & cfg){}
};

class ElseStatement : public IfStatement {
	public:
		ElseStatement(){}
		~ElseStatement(){}
		string virtual buildIR(CFG & cfg){}
};

class ElseSimple : public ElseStatement {
	public:
		ElseSimple(Instruction * i) : instruction(i) {}
		~ElseSimple(){}
	protected:
		Instruction* instruction;
};

class ElseCompose : public ElseStatement {
	public:
		ElseCompose(Instruction * i) : instruction(i) {}
		~ElseCompose(){}
		vector<Instruction*> instructions;
	protected:
		Instruction* instruction;
};

class TestExpression : public Instruction {
	public:
		TestExpression(){}
		~TestExpression(){}
		string virtual buildIR(CFG & cfg){}

};

class TestExpr : public TestExpression {
	public:
		TestExpr(Expression * e) : expression(e) {}
		~TestExpr() {}
		string buildIR(CFG & cfg){}

	protected:
		Expression * expression;
};

class TestExprLogique : public TestExpression {
	public:
		TestExprLogique(TestExpression * e1, TestExpression* e2, SigneLogique s) : expression1(e1), expression2(e2), signe(s) {}
		~TestExprLogique() {}
		string buildIR(CFG & cfg){}

	protected:
		TestExpression * expression1;
		TestExpression * expression2;
		SigneLogique signe;
};

class TestExprCompar : public TestExpression {
	public:
		TestExprCompar(TestExpression * e1, TestExpression* e2, SigneComparaison s) : expression1(e1), expression2(e2), signe(s) {}
		~TestExprCompar() {}
		string buildIR(CFG & cfg){}

	protected:
		TestExpression * expression1;
		TestExpression * expression2;
		SigneComparaison signe;
};


class Return : public Instruction {
	public:
		Return(Expression* expr) : expression(expr) { }
		string buildIR(CFG & cfg);
		~Return() { }
	protected:
		Expression* expression;
};

class Declaration {
	public:
		virtual ~Declaration() {cout << "== DESTRUCTING DECLARATION ==" << endl;}
		string getNomVariable();
		string virtual buildIR(CFG & cfg){}
	protected:
		Variable* variable;
};

class DeclarationSimple : public Declaration {
	public:
		DeclarationSimple(Variable* v) { variable = v; }
		virtual ~DeclarationSimple() {cout << "== DESTRUCTING DECLARATION SIMPLE ==" << endl;}
		string buildIR(CFG & cfg);
};

class DeclarationAvecAffectation : public Declaration {
	public:
		DeclarationAvecAffectation(Variable* v, Expression* expr): expression(expr) { variable = v; }
		virtual ~DeclarationAvecAffectation() {cout << "== DESTRUCTING DECLARATION AVEC AFF ==" << endl;}
		string buildIR(CFG & cfg);
	protected:
		Expression* expression;
};

class Bloc: public Instruction {
	public:
		Bloc(){}
		~Bloc() {}
		string buildIR(CFG & cfg) {}
		void ajouterDeclaration(Declaration* dec);
		void ajouterInstruction(Instruction* inst);
		vector<Declaration*> declarations;
		vector<Instruction*> instructions;
		map<string,int> variables;
		int index = -4;
};
class Fonction {
	public:
		Fonction(Bloc* b, string n): bloc(b), nom(n) {}
		void ajouterDeclaration(Declaration* dec){this->bloc->ajouterDeclaration(dec);}
		void ajouterInstruction(Instruction* inst){this->bloc->ajouterInstruction(inst);}
		string nom;
		Bloc* bloc;
};

class Programme {
	public:
		Programme(){}
		void ajouterFonction(Fonction* fct){fonctions.push_back(fct);}
		vector<CFG*> buildIR();

		vector<Fonction*> fonctions;

};
