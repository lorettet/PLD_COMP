
// Generated from expr.g4 by ANTLR 4.7.2

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

    virtual antlrcpp::Any visitExpr(exprParser::ExprContext *context) = 0;


};

