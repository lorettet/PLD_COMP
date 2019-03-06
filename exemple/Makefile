ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIME=/shares/public/tp/ANTLR4-CPP

ANTLRLOCAL=antlr4
ANTLRRUNTIMELOCAL=/usr/local

default:
	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  expr.g4
	clang++ -DTRACE -g -std=c++11   -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

local:
	$(ANTLRLOCAL) -visitor -no-listener -Dlanguage=Cpp expr.g4
	clang++ -DTRACE -g -std=c++11 -I $(ANTLRRUNTIMELOCAL)/include/antlr4-runtime/ *.cpp -o exe $(ANTLRRUNTIMELOCAL)/lib/libantlr4-runtime.a
