grammar expr;

axiome : fonction ; 
fonction : type nomFonction'('parametres')''{'instructions'}';
type : 'int';
nomFonction : 'main';
parametres : 
		| 'void';
instructions : 'return' INT';';

ESPACE : [ \n\t\r] -> skip;

INT : [0-9]+ ;


