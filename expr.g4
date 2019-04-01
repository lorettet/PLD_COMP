grammar expr;

programme : fonction+;

fonction : type ID'('parametres')''{'declarations* instructions*'}';

type : 'int';

parametres : 
		| 'void';
declarations : 
			type ID';' 			#declarationSimple
			| type ID '=' expression';'	#declarationAvecAffectation;

instructions : 
			ID'('parametres')';				#appel
			| ID '=' expression';'			#affectation
			| 'return' expression';'		#return;
			
expression : expression MULTDIV expression		#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'					#parenthese
			| [-]?valeur 						#val;
		
valeur : ID 	#variable
		| INT		#int;

ESPACE : [ \n\t\r] -> skip;

MULTDIV : [*/];
ADDSOUS : [+-];

ID : [a-zA-Z_]+;
INT : [0-9]+;
