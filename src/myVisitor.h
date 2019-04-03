// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"
#include "symboles.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by exprParser.
 */
class  MyVisitor : public exprVisitor {
public:

  /**
   * Visit parse trees produced by exprParser.
   */
    virtual antlrcpp::Any visitAxiome(exprParser::AxiomeContext *ctx) override {
    	return visit(ctx->fonction());
  	}

    virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override { 
    	return (Fonction*) new Fonction((Bloc*) visit(ctx->bloc()));
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

    virtual antlrcpp::Any visitInstrIF(exprParser::InstrIFContext *context) {
    	return visitChildren(context);
}


    virtual antlrcpp::Any visitIfSimpleInstr(exprParser::IfSimpleInstrContext *context) {
    	return visitChildren(context);
	}

    virtual antlrcpp::Any visitIfSimpleDecl(exprParser::IfSimpleDeclContext *context) {
    	return visitChildren(context);
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
    
    	if(ctx->ADDSOUS() && ctx->ADDSOUS()->getText() == "-") {
	    return (Expression*) new Soustraction(new Int(0),(Expression*)  visit(ctx->valeur()));
	}
	return (Expression*) new Addition(new Int(0), (Expression*) visit(ctx->valeur()));
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

};


