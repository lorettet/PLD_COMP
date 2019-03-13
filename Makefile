ANTLR=/shares/public/tp/ANTLR4-CPP/bin/antlr4
ANTLRRUNTIMEHEADERPATH=/shares/public/tp/ANTLR4-CPP/antlr4-runtime/
ANTLRRUNTIMELIB=/shares/public/tp/ANTLR4-CPP/lib/libantlr4-runtime.a

COMP=g++
EDL=g++
SRCDIR=src/
EXE=exe
EXEDIR=bin/
ANTLRDIR=antlr/
BINDIR=bin/
DEBUG=yes
G4=expr.g4
ANTLRFLAG=-visitor -no-listener -Dlanguage=Cpp
SRC=$(wildcard $(SRCDIR)*.cpp)
SRCANTLR=$(wildcard $(ANTLRDIR)*.cpp)
OBJ1:=$(SRC:.cpp=.o)
OBJ2:=$(SRCANTLR:.cpp=.o)
OBJ:=$(subst src,bin/binsrc,$(OBJ1))
OBJANTLR:=$(subst antlr,bin/binantlr,$(OBJ2))

ECHO=@echo
GREEN="\033[32m"
CANCELCOLOR="\033[0m"


ifeq ($(DEBUG),yes)
	#$(ECHO) $(GREEN)Mode Debug
	DEBUGFLAG=-DTRACE
else
	#$(ECHO) $(GREEN)Mode Release
	DEBUGFLAG=
endif

COMPFLAG=-g -std=c++11 $(DEBUGFLAG) -Wno-attributes

#default:
#	$(ANTLR) -visitor -no-listener -Dlanguage=Cpp  expr.g4
#	clang++ -DTRACE -g -std=c++11   -I $(ANTLRRUNTIME)/antlr4-runtime/ *.cpp -o exe $(ANTLRRUNTIME)/lib/libantlr4-runtime.a

.PHONY: g4 clean

all: $(EXEDIR)$(EXE)
	@echo $(GREEN)Done$(CANCELCOLOR)


g4:$(G4)
	$(ECHO) $(GREEN)Generation antlr$(CANCELCOLOR)
	$(ANTLR) $(ANTLRFLAG) $(G4) -o $(ANTLRDIR)



$(EXEDIR)$(EXE):$(OBJ) $(OBJANTLR)
	$(ECHO) $(GREEN)Edition des liens$(CANCELCOLOR)
	$(EDL) -o $@ $^ $(ANTLRRUNTIMELIB)


$(BINDIR)binantlr/%.o: $(ANTLRDIR)%.cpp
	$(ECHO) $(GREEN)Compilation : $<$(CANCELCOLOR)
	$(COMP) -o $@ -c $< $(COMPFLAG) -I $(ANTLRRUNTIMEHEADERPATH)

$(BINDIR)binsrc/%.o: $(SRCDIR)%.cpp
	$(ECHO) $(GREEN)Compilation : $<$(CANCELCOLOR)
	$(COMP) -o $@ -c $< $(COMPFLAG) -I antlr/ -I $(ANTLRRUNTIMEHEADERPATH)


clean:
	-rm antlr/* bin/bin*/* a.out main.s main.o bin/exe
