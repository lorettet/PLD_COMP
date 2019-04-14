#include <iostream>

#include "antlr4-runtime.h"
#include "../antlr/exprLexer.h"
#include "../antlr/exprParser.h"
#include "myVisitor.h"
#include "ASMWriter_x86.h"
#include "exception.h"

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
    tree::ParseTree* tree = parser.programme();
    assert(tree);
    MyVisitor visitor;
    Programme* p = visitor.visit(tree); // construit l'AST
		try {
			ASMWriter_x86 asmb("main.s");
			vector<CFG*> cfgs = p->buildIR(); //construit un CFG par fonction et genere l'IR : appel recursif sur chaque element de chaque fonction : CFG->buildIR() appelle fonction->buildIR() qui appelle declaration->buildIR() et instruction->buildIR() pour chaque instruction
			for(auto cfg : cfgs)
			{
				cfg->gen_asm(asmb); //Genere l'assembleur de chaque fonction
			}
			cout << "Writing ASM" << endl;
			asmb.writeASM();// ecrit l'assembleur
		}
		catch(UndefindedVarException & e)
		{
			cerr << "[ERROR] " <<e.what() << endl;
			return 1;
		}

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
