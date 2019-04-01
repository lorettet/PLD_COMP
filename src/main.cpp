#include <iostream>

#include "antlr4-runtime.h"
#include "../antlr/exprLexer.h"
#include "../antlr/exprParser.h"
#include "myVisitor.h"
#include "ASMWriter_x86.h"

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
    Fonction* f = visitor.visit(tree);
		ASMWriter_x86 asmb("main.s");
		CFG cfg(f);
		cfg.buildIR();
		cout << "CFG IR done" << endl;
		cfg.gen_asm(asmb);
		asmb.writeASM();

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
