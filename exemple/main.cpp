#include <iostream>

#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"

#include "dotexport.h"

using namespace antlr4;

int main(int , const char **) {
  ANTLRInputStream input("1+3");
  exprLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  exprParser parser(&tokens);
  tree::ParseTree* tree = parser.expr();

  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

  DotExport dotexport(&parser);
  tree::ParseTreeWalker::DEFAULT.walk(&dotexport,tree);
  ofstream out;
  out.open("tmp.dot");
  out<<dotexport.getDotFile();
  out.close();
  system("dot -Tpdf -o out.pdf tmp.dot");

  return 0;
}
