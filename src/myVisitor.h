/*#pragma once

#include "antlr4-runtime.h"
#include "exprVisitor.h"
#include "stdlib.h"

class  MyVisitor : public exprVisitor {
public:

  virtual antlrcpp::Any visitAxiome(exprParser::AxiomeContext *ctx) override {
    return (int)visit(ctx->fonction());
  }

  virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override {
    return (int)visit(ctx->instructions());
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

  virtual antlrcpp::Any visitInstructions(exprParser::InstructionsContext *ctx) override {
    return atoi(ctx->INT()->getText().c_str());
  }


};*/

#pragma once


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

  virtual antlrcpp::Any visitSimple(exprParser::SimpleContext *ctx) override {
    return (Declaration*) new DeclarationSimple(new Variable(ctx->VARIABLE()->getText().c_str()));
  }

  virtual antlrcpp::Any visitAvecAffectation(exprParser::AvecAffectationContext *ctx) override {
    return (Declaration*) new DeclarationAvecAffectation(new Variable(ctx->VARIABLE()->getText().c_str()), new Expression(visit(ctx->expression())));
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
	  return (Instruction*) new Affectation(new Variable(ctx->VARIABLE()->getText().c_str()), (Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
	  return (Instruction*) new Return((Expression*) visit(ctx->expression()));
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
	  return (Expression*) new Variable(ctx->VARIABLE()->getText().c_str());
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
	  return (Expression*) new Int(atoi(ctx->INT()->getText().c_str()));
  }


};

