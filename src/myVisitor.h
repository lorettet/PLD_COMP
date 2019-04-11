// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"
#include "symboles.h"

class  MyVisitor : public exprVisitor {
public:

  virtual antlrcpp::Any visitProgramme(exprParser::ProgrammeContext *ctx) override {
    Programme* p = new Programme();
    for(auto fonction : ctx->fonction()) {
			p->ajouterFonction(visit(fonction));
		}
		return p;
  }

  virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override {
    return new Fonction((ParametresFormels*) visit(ctx->parametresFormels()), (Bloc*) visit(ctx->bloc()), ctx->ID()->getText());
  }

  virtual antlrcpp::Any visitParametre(exprParser::ParametreContext *ctx) override {
    return new Parametre(ctx->ID()->getText(), ctx->TYPE()->getText());
  }

  virtual antlrcpp::Any visitParametresFormels(exprParser::ParametresFormelsContext *ctx) override {
		ParametresFormels * pf = new ParametresFormels();

		for (auto parametre : ctx->parametre()){
			pf->ajouterParametre((Parametre*)visit(parametre));
		}
		return pf;
  }

  virtual antlrcpp::Any visitParametresEffectifs(exprParser::ParametresEffectifsContext *ctx) override {
	  ParametresEffectifs* pe = new ParametresEffectifs();

	  for (auto expression : ctx->expression()){
		  pe->ajouterExpression((Expression*) visit(expression));
	  }
	  return pe;
  }

	virtual antlrcpp::Any visitBloc(exprParser::BlocContext *ctx) override {
		Bloc* b = new Bloc();
		for(auto declaration : ctx->declarations()) {
			b->ajouterDeclaration(visit(declaration));
		}
		for(auto instruction : ctx->instructions()) {
			b->ajouterInstruction(visit(instruction));
		}
		return b;
	}

  virtual antlrcpp::Any visitExpressionSeule(exprParser::ExpressionSeuleContext *ctx) override {
    return (Instruction*) new ExpressionSeule((Expression*) visit(ctx->expression()));
  }

	virtual antlrcpp::Any visitDeclarationSimple(exprParser::DeclarationSimpleContext *ctx) override {
		return (Declaration*) new DeclarationSimple(new Variable(ctx->ID()->getText()));
	}

	virtual antlrcpp::Any visitDeclarationAvecAffectation(exprParser::DeclarationAvecAffectationContext *ctx) override {
		return (Declaration*) new DeclarationAvecAffectation(new Variable(ctx->ID()->getText()), (Expression*) visit(ctx->expression()));
	}

	virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
		return (Instruction*) new Affectation(new Variable(ctx->ID()->getText()), (Expression*) visit(ctx->expression()));
	}


	virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
		return (Instruction*) new Return((Expression*) visit(ctx->expression()));
	}

    virtual antlrcpp::Any visitInstrIF(exprParser::InstrIFContext *ctx) override {
    	return (Instruction*) ((IfStatement*) visit(ctx->ifStatement()));
	}

	virtual antlrcpp::Any visitInstrWHILE(exprParser::InstrWHILEContext *ctx) override {
    	return (Instruction*) ((WhileStatement*) visit(ctx->whileStatement()));
	}

 	virtual antlrcpp::Any visitIfInstr(exprParser::IfInstrContext *ctx) override {
	  if (ctx->elseStatement()) {
	  	return (IfStatement*) new IfInstr(visit(ctx->testExpression()), visit(ctx->instructions()), visit(ctx->elseStatement()));
	  }
	  return (IfStatement*) new IfInstr(visit(ctx->testExpression()), visit(ctx->instructions()), nullptr);
	}

	virtual antlrcpp::Any visitWhileInstr(exprParser::WhileInstrContext *ctx) override {
		return (WhileStatement*) new WhileInstr(visit(ctx->testExpression()), visit(ctx->instructions()));
	}

	virtual antlrcpp::Any visitIfSimpleDecl(exprParser::IfSimpleDeclContext *ctx) override {
	    if (ctx->elseStatement()) {
    		return (IfStatement*) new IfSimpleDecl((TestExpression*) visit(ctx->testExpression()), visit(ctx->declarations()), visit(ctx->elseStatement()));
	    }
	    return (IfStatement*) new IfSimpleDecl((TestExpression*) visit(ctx->testExpression()), visit(ctx->declarations()), nullptr);
	}

	virtual antlrcpp::Any visitBlocSimple(exprParser::BlocSimpleContext *ctx) override {
		Bloc * bloc = visit(ctx->bloc());
		Instruction * inst  = (Instruction*) bloc;
		return (Instruction*) inst;
	}


	virtual antlrcpp::Any visitElseIF(exprParser::ElseIFContext *ctx) override {
		return (ElseStatement*) new ElseIf((IfStatement*)visit(ctx->ifStatement()));
	}

	virtual antlrcpp::Any visitElseSimple(exprParser::ElseSimpleContext *ctx) override {
		return (ElseStatement*) new ElseSimple((Instruction*)visit(ctx->instructions()));
	}


  virtual antlrcpp::Any visitTestExprLogique(exprParser::TestExprLogiqueContext *ctx) override {
		if(ctx->SIGNELOGIQUE()->getText() == "&&") {
			return (TestExpression*) new TestExprLogique(visit(ctx->testExpression(0)), visit(ctx->testExpression(1)), ET);
		}
		return (TestExpression*) new TestExprLogique(visit(ctx->testExpression(0)), visit(ctx->testExpression(1)), OU);
	}

  virtual antlrcpp::Any visitTestExprPar(exprParser::TestExprParContext *ctx) override {
    	return (TestExpression*) new TestExprPar((TestExpression*) visit(ctx->testExpression()));
	}	
	
    virtual antlrcpp::Any visitTestExprCompar(exprParser::TestExprComparContext *ctx) override {
	    string signe = ctx->SIGNECOMPARAISON()->getText();
			if(signe == "<=") {
				return (TestExpression*) new TestExprCompar(visit(ctx->expression(0)), visit(ctx->expression(1)), INFEGAL);
			}
			else if(signe == ">=") {
				return (TestExpression*) new TestExprCompar(visit(ctx->expression(0)), visit(ctx->expression(1)), SUPEGAL);
			} else if(signe == "==") {
				return (TestExpression*) new TestExprCompar((Expression*) visit(ctx->expression(0)), (Expression*) visit(ctx->expression(1)), EGAL);
			} else if(signe == "!=") {
				return (TestExpression*) new TestExprCompar(visit(ctx->expression(0)), visit(ctx->expression(1)), DIFF);
			} else if(signe == ">") {
				return (TestExpression*) new TestExprCompar(visit(ctx->expression(0)), visit(ctx->expression(1)), SUPSTRICT);
			}
			return (TestExpression*) new TestExprCompar(visit(ctx->expression(0)), visit(ctx->expression(1)), INFSTRICT);
	}
	
  virtual antlrcpp::Any visitNot(exprParser::NotContext *ctx) override {
    	return (TestExpression*) new Not((TestExpression*) ctx->testExpression());
	}
	
  virtual antlrcpp::Any visitTestExpressionSimple(exprParser::TestExpressionSimpleContext *ctx) override {
    	return (TestExpression*) new TestExpressionSimple((Expression*)visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitVal(exprParser::ValContext *ctx) override {
    return visit(ctx->valeur());
  }

  virtual antlrcpp::Any visitExpressionAddSous(exprParser::ExpressionAddSousContext *ctx) override {
    if(ctx->ADDSOUS()->getText() == "-") {
    	return (Expression*) new Soustraction((Expression*) visit(ctx->expression(0)),(Expression*) visit(ctx->expression(1)));
    }
    return (Expression*) new Addition((Expression*) visit(ctx->expression(0)),(Expression*) visit(ctx->expression(1)));
  }

  virtual antlrcpp::Any visitExpressionMultDiv(exprParser::ExpressionMultDivContext *ctx) override {
    if(ctx->MULTDIV()->getText() == "*") {
    	return (Expression*) new Multiplication((Expression*) visit(ctx->expression(0)),(Expression*) visit(ctx->expression(1)));
    }
    return (Expression*) new Division((Expression*) visit(ctx->expression(0)),(Expression*) visit(ctx->expression(1)));
  }

  virtual antlrcpp::Any visitExpressionUnaire(exprParser::ExpressionUnaireContext *ctx) override {
	  if(ctx->ADDSOUS()->getText() == "+") return (Expression*) visit(ctx->expression());
	  return (Expression*) new ExpressionUnaire((Expression*) visit(ctx->expression()), ctx->ADDSOUS()->getText() == "-");
  }

  virtual antlrcpp::Any visitParenthese(exprParser::ParentheseContext *ctx) override {
    return (Expression*) new Parenthese((Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitAppel(exprParser::AppelContext *ctx) override {
	  return (Expression*) new Appel(ctx->ID()->getText(), (ParametresEffectifs*) visit(ctx->parametresEffectifs()));
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
    return (Expression*) new Variable(ctx->ID()->getText());
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
    return (Expression*) new Int(atoi(ctx->INT()->getText().c_str()));
  }


};
