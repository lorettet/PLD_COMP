#include <map>
#include <vector>
#include <string>

using namespace std;
class Expression {
	public:
		Expression() { }
		virtual ~Expression(){}
};

class Int : public Expression{
	public:
		Int(int val) : valeur(val) { }
		~Int() { }
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
};

class Affectation : public Instruction {
	public:
		Affectation(Variable* var, Expression* expr) : variable(var), expression(expr) { }
		~Affectation() { }
	protected:
		Variable* variable;
		Expression* expression;
};

class Return : public Instruction {
	public:
		Return(Expression* expr) : expression(expr) { }
		~Return() { }
	protected:
		Expression* expression;
};

class Declaration {
	public:
		~Declaration();
		string getNomVariable();
	protected:
		Variable* variable;
};

class DeclarationSimple : public Declaration {
	public:
		DeclarationSimple(Variable* v) { variable = v; }
};

class DeclarationAvecAffectation : public Declaration {
	public:
		DeclarationAvecAffectation(Variable* v, Expression* expr): expression(expr) { variable = v; }
	protected:
		Expression* expression;
};

class Fonction {
	public:
		Fonction() {}
		void ajouterDeclaration(Declaration* dec);
		void ajouterInstruction(Instruction* inst);
	protected:
		vector<Declaration*> declarations;
		vector<Instruction*> instructions;
		map<string,int> variables;
		int index = 0;
};
