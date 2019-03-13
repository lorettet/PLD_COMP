#include <iostream>

#include <fstream>
#include <string.h>
#include "ASMWriter.h"

using namespace std;


int main (int argc, char *argv[]) {

	ASMWriter asmw("main.s");
	asmw.addDeclaration("i");
	asmw.addAffectation("i",53);
	asmw.addDeclarationAndAffectation("j","i");
	asmw.addReturn("j");
	asmw.writeASM();

	return 0;
}
