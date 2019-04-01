grammar expr;

programme : fonction+;

fonction : TYPE ID'('parametresFormels')''{'declarations* instructions*'}';


parametresFormels : (parametre(','parametre)*)*;

parametre : TYPE ID;

parametresEffectifs : (expression(','expression)*)*;

declarations : 
			TYPE ID';' 					#declarationSimple
			| TYPE ID '=' expression';'	#declarationAvecAffectation;

instructions : 
			ID'('parametresEffectifs');'	#appel
			| ID '=' expression';'			#affectation
			| 'return' expression';'		#return;
			
expression : expression MULTDIV expression			#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'			#parenthese
			| ADDSOUS? valeur 			#val;
			
		
valeur : ID 	#variable
		| INT	#int;


ESPACE : [ \n\t\r] -> skip;

MULTDIV : [*/];
ADDSOUS : [+-];

TYPE : 'int';

ID : [a-zA-Z_]+;
INT : [0-9]+ ;
