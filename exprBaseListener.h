
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprListener.h"


/**
 * This class provides an empty implementation of exprListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  exprBaseListener : public exprListener {
public:

  virtual void enterAxiome(exprParser::AxiomeContext * /*ctx*/) override { }
  virtual void exitAxiome(exprParser::AxiomeContext * /*ctx*/) override { }

  virtual void enterFonction(exprParser::FonctionContext * /*ctx*/) override { }
  virtual void exitFonction(exprParser::FonctionContext * /*ctx*/) override { }

  virtual void enterType(exprParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(exprParser::TypeContext * /*ctx*/) override { }

  virtual void enterNomFonction(exprParser::NomFonctionContext * /*ctx*/) override { }
  virtual void exitNomFonction(exprParser::NomFonctionContext * /*ctx*/) override { }

  virtual void enterParametres(exprParser::ParametresContext * /*ctx*/) override { }
  virtual void exitParametres(exprParser::ParametresContext * /*ctx*/) override { }

  virtual void enterInstructions(exprParser::InstructionsContext * /*ctx*/) override { }
  virtual void exitInstructions(exprParser::InstructionsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

