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

class ValCaseTab: public Valeur {
	public:
		ValCaseTab(string s, Expression* expr) : nom(s), expression(expr) {}
		~ValCaseTab() {}
		string getNomVariable();
		Expression * getExpression() { return expression; }
		string buildIR(CFG & cfg) {}
	protected:
		string nom;
		Expression* expression;
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
		int getNbParams(){return listParams.size();}
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

class Declaration {
	public:
		virtual ~Declaration() {cout << "== DESTRUCTING DECLARATION ==" << endl;}
		string getNomVariable();
		string virtual buildIR(CFG & cfg){}
	protected:
		Variable* variable;
};

class ExpressionSeule : public Instruction {
	public:
		ExpressionSeule(Expression* expr) : expression(expr) {}
		virtual ~ExpressionSeule() {}
		string buildIR(CFG & cfg);
	protected:
		Expression* expression;
};

class ExpressionTab : public Expression {
	public:
		ExpressionTab(){}
		virtual ~ExpressionTab(){}
		string virtual buildIR(CFG & cfg){}
		
		void ajouterExpression(Expression* e){tabExpressions.push_back(e);}
		
	protected:
		vector<Expression*> tabExpressions;
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



class IfStatement : public Instruction {
	public:
		IfStatement(){}
		~IfStatement(){}
		string virtual buildIR(CFG & cfg){}
};

class WhileStatement : public Instruction {
	public:
		WhileStatement(){}
		~WhileStatement(){}
		string virtual buildIR(CFG & cfg){}
};

class ElseStatement : public IfStatement {
	public:
		ElseStatement(){}
		~ElseStatement(){}
		string virtual buildIR(CFG & cfg, BasicBlock* afterBB){}
};

class TestExpression {
	public:
		TestExpression(){}
		~TestExpression(){}
		string virtual buildIR(CFG & cfg){}
};

class IfInstr: public IfStatement {
	public:
		IfInstr(TestExpression* tE, Instruction* instr, ElseStatement* els): testExpression(tE), instruction(instr), elseStatement(els) {}
		~IfInstr() {}
		string virtual buildIR(CFG& cfg);
	protected:
		TestExpression* testExpression;
		Instruction* instruction;
		ElseStatement* elseStatement;
};

class WhileInstr: public WhileStatement {
	public:
		WhileInstr(TestExpression* tE, Instruction* instr): testExpression(tE), instruction(instr) {}
		~WhileInstr() {}
		string virtual buildIR(CFG& cfg);
	protected:
		TestExpression* testExpression;
		Instruction* instruction;
};

class IfSimpleDecl: public IfStatement {
	public:
		IfSimpleDecl(TestExpression* tE, Declaration* decl, ElseStatement* els): testExpression(tE), declaration(decl), elseStatement(els) {}
		~IfSimpleDecl() {}
		string virtual buildIR(CFG& cfg) {}
	protected:
		TestExpression* testExpression;
		Declaration* declaration;
		ElseStatement* elseStatement;
};

class ElseSimple : public ElseStatement {
	public:
		ElseSimple(Instruction * i) : instruction(i) {}
		~ElseSimple(){}
		string virtual buildIR(CFG & cfg, BasicBlock* afterBB);
	protected:
		Instruction* instruction;
};

class ElseIf : public ElseStatement {
	public:
		ElseIf(IfStatement* ifS) : ifStatement(ifS) {}
		~ElseIf(){}
		string virtual buildIR(CFG & cfg, BasicBlock* afterBB);
	protected:
		IfStatement* ifStatement;
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
		TestExprCompar(Expression * e1, Expression* e2, SigneComparaison s) : expression1(e1), expression2(e2), signe(s) {}
		~TestExprCompar() {}
		string buildIR(CFG & cfg);

	protected:
		Expression * expression1;
		Expression * expression2;
		SigneComparaison signe;
};

class Not: public TestExpression {
	public:
		Not(TestExpression * e1) : expression(e1) {}
		~Not() {}
		string buildIR(CFG & cfg);

	protected:
		TestExpression * expression;
};

class TestExprPar: public TestExpression {
	public:
		TestExprPar(TestExpression * e1) : expression(e1) {}
		~TestExprPar() {}
		string buildIR(CFG & cfg){}

	protected:
		TestExpression * expression;
};

class TestExpressionSimple: public TestExpression {
	public:
		TestExpressionSimple(Expression * e1) : expression(e1) {}
		~TestExpressionSimple() {}
		string buildIR(CFG & cfg);

	protected:
		Expression * expression;
};

class Return : public Instruction {
	public:
		Return(Expression* expr) : expression(expr) { }
		string buildIR(CFG & cfg);
		~Return() { }
	protected:
		Expression* expression;
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

class DeclarationTabSimple : public Declaration {
	public:
		DeclarationTabSimple(Variable* v, int t) { variable = v; taille = t;}
		virtual ~DeclarationTabSimple() {cout << "== DESTRUCTING DECLARATION TAB SIMPLE ==" << endl;}
		string buildIR(CFG & cfg) {}
		
		int taille;
};

class DeclarationTabAvecAffectation : public Declaration {
	public:
		DeclarationTabAvecAffectation(Variable* v, int t, ExpressionTab* expr) {expression = expr; variable = v; taille = t;}
		virtual ~DeclarationTabAvecAffectation() {cout << "== DESTRUCTING DECLARATION TAB AVEC AFF ==" << endl;}
		string buildIR(CFG & cfg) {}
		
		int taille;
	protected:
		ExpressionTab* expression;
};

class Bloc: public Instruction {
	public:

		Bloc(){parent = nullptr;}
		~Bloc() {}
		string buildIR(CFG & cfg);
		void ajouterDeclaration(Declaration* dec){
			declarations.push_back(dec);
			variables[dec->getNomVariable()] = 4;
		}
		void ajouterInstruction(Instruction* inst){instructions.push_back(inst);};
		string hasLocalVariable(string var);
		vector<Declaration*> declarations;
		vector<Instruction*> instructions;
		map<string,int> variables;
		int index = 0;
		Bloc* parent;

};
class Fonction {
	public:
		Fonction(ParametresFormels* p, Bloc* b, string n): params(p), bloc(b), nom(n) {
			for(auto param : p->listParams)
			{
				bloc->variables[param->nom] = atoi(param->type.c_str());
			}
		}
		virtual ~Fonction() {}
		void buildIR(CFG & cfg);
		void ajouterDeclaration(Declaration* dec){this->bloc->ajouterDeclaration(dec);}
		void ajouterInstruction(Instruction* inst){this->bloc->ajouterInstruction(inst);}
		string nom;
		Bloc* bloc;
		ParametresFormels* params;
};

class Programme {
	public:
		Programme(){}
		void ajouterFonction(Fonction* fct){fonctions.push_back(fct);}
		vector<CFG*> buildIR();

		vector<Fonction*> fonctions;

};
