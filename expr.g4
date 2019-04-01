grammar expr;

programme : fonction+;

fonction : type ID'('parametresFormels')''{'declarations* instructions*'}';

type : 'int';

parametresFormels : (type ID(','type ID)*)*;

parametresEffectifs : (expression(','expression)*)*;

declarations : 
			type ID';' 			#declarationSimple
			| type ID '=' expression';'	#declarationAvecAffectation;

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

ID : [a-zA-Z_]+;
INT : [0-9]+;
