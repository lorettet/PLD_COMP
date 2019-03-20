grammar expr;

axiome : fonction ; 
fonction : type nomFonction'('parametres')''{'declarations* instructions*'}';
type : 'int';
nomFonction : 'main';
parametres : 
		| 'void';
declarations : 
			type VARIABLE';' 					#declarationSimple
			| type VARIABLE '=' expression';'	#declarationAvecAffectation;

instructions : 
			VARIABLE '=' expression';'		#affectation
			| 'return' expression';'		#return;
			
expression : expression MULTDIV expression		#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'					#parenthese
			| valeur 							#val;
		
valeur : VARIABLE 	#variable
		| INT		#int;

ESPACE : [ \n\t\r] -> skip;

MULTDIV : [*/];
ADDSOUS : [+-];

VARIABLE : [a-zA-Z]+;
INT : [0-9]+ ;
