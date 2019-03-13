grammar expr;

axiome : fonction ; 
fonction : type nomFonction'('parametres')''{'declarations* instructions*'}';
type : 'int';
nomFonction : 'main';
parametres : 
		| 'void';
declarations : 
			type VARIABLE';' 					#simple
			| type VARIABLE '=' expression';'	#avecAffectation;

instructions : 
			VARIABLE '=' expression';'		#affectation
			| 'return' expression';'		#return;
		
expression : 
			VARIABLE 	#variable
			| INT		#int;

ESPACE : [ \n\t\r] -> skip;

VARIABLE : [a-zA-Z]+;
INT : [0-9]+ ;
