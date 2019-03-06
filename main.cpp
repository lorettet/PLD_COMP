#include <iostream>

#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "myVisitor.h"

using namespace std;

using namespace antlr4;

int main(){
	
	ANTLRInputStream input("int main(){return 42;}");
  	exprLexer lexer(&input);
  	CommonTokenStream tokens(&lexer);

    exprParser parser(&tokens);
    tree::ParseTree* tree = parser.axiome();
    MyVisitor visitor;
    int i = visitor.visit(tree);
    
    
    
    cout << i << endl;
    
	return 0;
}
