/*#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"
#include "symboles.h"

class  MyVisitor : public exprVisitor {
public:

    virtual antlrcpp::Any visitAxiome(exprParser::AxiomeContext *ctx) override {
    	return visit(ctx->fonction());
  	}

    virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override {
		Fonction* f = new Fonction();
		for(auto declaration : ctx->declarations()) {
		  f->ajouterDeclaration(visit(declaration));
		}
		for(auto instruction : ctx->instructions()) {
		  f->ajouterInstruction(visit(instruction));
		}
    	return f;
	}

    virtual antlrcpp::Any visitType(exprParser::TypeContext *ctx) override {
    	return visitChildren(ctx);
  	}

    virtual antlrcpp::Any visitNomFonction(exprParser::NomFonctionContext *ctx) override {
    	return visitChildren(ctx);
  	}

    virtual antlrcpp::Any visitParametres(exprParser::ParametresContext *ctx) override {
    	return visitChildren(ctx);
  	}

    virtual antlrcpp::Any visitDeclarationSimple(exprParser::DeclarationSimpleContext *ctx) override {
		return (Declaration*) new DeclarationSimple(new Variable(ctx->VARIABLE()->getText()));
  	}

    virtual antlrcpp::Any visitDeclarationAvecAffectation(exprParser::DeclarationAvecAffectationContext *ctx) override {
		return (Declaration*) new DeclarationAvecAffectation(new Variable(ctx->VARIABLE()->getText()), (Expression*) visit(ctx->expression()));
	}

    virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
		return (Instruction*) new Affectation(new Variable(ctx->VARIABLE()->getText()), (Expression*) visit(ctx->expression()));
	}

    virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
		return (Instruction*) new Return((Expression*) visit(ctx->expression()));
	}
    
    virtual antlrcpp::Any visitVal(exprParser::ValContext *ctx) override {
	    return (Expression*) visit(ctx->valeur());
    }

    virtual antlrcpp::Any visitParenthese(exprParser::ParentheseContext *ctx) override {
	    return (Expression*) new Parenthese((Expression*) visit(ctx->expression()));
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
    
    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
		return (Expression*) new Variable(ctx->VARIABLE()->getText());
	}

    virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
		return (Expression*) new Int(atoi(ctx->INT()->getText().c_str()));
	}




};*/


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
    Fonction* f = new Fonction();
    f->nom = ctx->ID()->getText();
	for(auto declaration : ctx->declarations()) {
	  f->ajouterDeclaration(visit(declaration));
	}
	for(auto instruction : ctx->instructions()) {
	  f->ajouterInstruction(visit(instruction));
	}
	return f;
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

  virtual antlrcpp::Any visitDeclarationSimple(exprParser::DeclarationSimpleContext *ctx) override {
    return (Declaration*) new DeclarationSimple(new Variable(ctx->ID()->getText()));
  }

  virtual antlrcpp::Any visitDeclarationAvecAffectation(exprParser::DeclarationAvecAffectationContext *ctx) override {
	return (Declaration*) new DeclarationAvecAffectation(new Variable(ctx->ID()->getText()), (Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitAppel(exprParser::AppelContext *ctx) override {
	  return (Instruction*) new Appel(ctx->ID()->getText(), (ParametresEffectifs*) visit(ctx->parametresEffectifs()));
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
    return (Instruction*) new Affectation(new Variable(ctx->ID()->getText()), (Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
    return (Instruction*) new Return((Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitVal(exprParser::ValContext *ctx) override {
    return (Expression*) visit(ctx->valeur());
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

  virtual antlrcpp::Any visitParenthese(exprParser::ParentheseContext *ctx) override {
    return (Expression*) new Parenthese((Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
    return (Expression*) new Variable(ctx->ID()->getText());
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
    return (Expression*) new Int(atoi(ctx->INT()->getText().c_str()));
  }


};



