
// Generated from expr.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "exprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by exprParser.
 */
class  exprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by exprParser.
   */
    virtual antlrcpp::Any visitAxiome(exprParser::AxiomeContext *context) = 0;

    virtual antlrcpp::Any visitFonction(exprParser::FonctionContext *context) = 0;

    virtual antlrcpp::Any visitType(exprParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitNomFonction(exprParser::NomFonctionContext *context) = 0;

    virtual antlrcpp::Any visitParametres(exprParser::ParametresContext *context) = 0;

    virtual antlrcpp::Any visitSimple(exprParser::SimpleContext *context) = 0;

    virtual antlrcpp::Any visitAvecAffectation(exprParser::AvecAffectationContext *context) = 0;

    virtual antlrcpp::Any visitAffectation(exprParser::AffectationContext *context) = 0;

    virtual antlrcpp::Any visitReturn(exprParser::ReturnContext *context) = 0;

    virtual antlrcpp::Any visitVariable(exprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitInt(exprParser::IntContext *context) = 0;


};

