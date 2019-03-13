#include <iostream>

#include "antlr4-runtime.h"
#include "exprLexer.h"
#include "exprParser.h"
#include "myVisitor.h" 

#include <fstream>
#include <string>

using namespace std;

using namespace antlr4;

string lireFichier(string nomFichier);

int main (int argc, char *argv[]) {
	assert(argc == 2);
	string programme = lireFichier(argv[1]);

	ANTLRInputStream input(programme);
  	exprLexer lexer(&input);
  	CommonTokenStream tokens(&lexer);

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

string lireFichier(string nomFichier) {
	string programme;
	string line;
	ifstream fichierProgramme (nomFichier);
	if (fichierProgramme.is_open())
	{
		while ( getline (fichierProgramme,line) )
		{
			programme += line;
		}
		fichierProgramme.close();
	}
	  else cout << "Unable to open file";
	  return programme;
}
