#pragma once

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


};

