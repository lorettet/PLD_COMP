
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprVisitor.h"


/**
 * This class provides an empty implementation of exprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  exprBaseVisitor : public exprVisitor {
public:

  virtual antlrcpp::Any visitAxiome(exprParser::AxiomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *ctx) override {
    return visitChildren(ctx);
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
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAvecAffectation(exprParser::AvecAffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(exprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt(exprParser::IntContext *ctx) override {
    return visitChildren(ctx);
  }


};

