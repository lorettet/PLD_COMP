
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by exprParser.
 */
class  exprListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterAxiome(exprParser::AxiomeContext *ctx) = 0;
  virtual void exitAxiome(exprParser::AxiomeContext *ctx) = 0;

  virtual void enterFonction(exprParser::FonctionContext *ctx) = 0;
  virtual void exitFonction(exprParser::FonctionContext *ctx) = 0;

  virtual void enterType(exprParser::TypeContext *ctx) = 0;
  virtual void exitType(exprParser::TypeContext *ctx) = 0;

  virtual void enterNomFonction(exprParser::NomFonctionContext *ctx) = 0;
  virtual void exitNomFonction(exprParser::NomFonctionContext *ctx) = 0;

  virtual void enterParametres(exprParser::ParametresContext *ctx) = 0;
  virtual void exitParametres(exprParser::ParametresContext *ctx) = 0;

  virtual void enterInstructions(exprParser::InstructionsContext *ctx) = 0;
  virtual void exitInstructions(exprParser::InstructionsContext *ctx) = 0;


};

