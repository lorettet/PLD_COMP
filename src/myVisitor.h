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

    virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override { 
    	return (Fonction*) new Fonction((Bloc*) visit(ctx->bloc()), ctx->ID()->getText());
	}

    virtual antlrcpp::Any visitBloc(exprParser::BlocContext *context) override {
	Bloc* b = new Bloc();
	for(auto declaration : context->declarations()) {
	  b->ajouterDeclaration(visit(declaration));
	}
	for(auto instruction : context->instructions()) {
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

    virtual antlrcpp::Any visitInstrIF(exprParser::InstrIFContext *context) {
    	return visitChildren(context);
}


    virtual antlrcpp::Any visitIfSimpleInstr(exprParser::IfSimpleInstrContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitIfSimpleDecl(exprParser::IfSimpleDeclContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitBlocSimple(exprParser::BlocSimpleContext *context){
	Bloc * bloc = visit(context->bloc());
	Instruction * inst  = (Instruction*) bloc;
	return (Instruction*) inst;
}

    virtual antlrcpp::Any visitIfCompose(exprParser::IfComposeContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitElseIF(exprParser::ElseIFContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitElseSimple(exprParser::ElseSimpleContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitElseCompose(exprParser::ElseComposeContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitTestExpr(exprParser::TestExprContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitTestExprLogique(exprParser::TestExprLogiqueContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitTestExprCompar(exprParser::TestExprComparContext *context) {
    	return visitChildren(context);
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
