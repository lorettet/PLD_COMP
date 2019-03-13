#include <iostream>

#include <fstream>
#include <string.h>
#include "ASMWriter.h"

using namespace std;


int main (int argc, char *argv[]) {
    exprParser parser(&tokens);
    tree::ParseTree* tree = parser.axiome();
    assert(tree);
    MyVisitor visitor;
    int i = visitor.visit(tree);
    
    ofstream assembleur;
	assembleur.open ("main.s");
	assembleur << ".text\n \
	.global main\n \
	main:movl $" << i << ", %eax\n \
	ret" << endl;
	assembleur.close();


	return 0;
}
