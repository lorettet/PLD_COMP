grammar expr;

programme : fonction+;

fonction : TYPE ID'('parametresFormels')' bloc;
bloc: '{'declarations* instructions*'}';

parametresFormels : (parametre(','parametre)*)*;

parametre : TYPE ID;

parametresEffectifs : (expression(','expression)*)*;

declarations :
			TYPE ID';' 					#declarationSimple
			| TYPE ID '=' expression';'			#declarationAvecAffectation;

instructions : expression';'					#expressionSeule
			| ID '=' expression';'			#affectation
			| 'return' expression';'		#return
			| ifStatement				#instrIF
			| bloc					#blocSimple;


ifStatement:
	'if' '(' testExpression ')' instructions elseStatement?	#ifSimpleInstr
	| 'if' '(' testExpression ')' declarations elseStatement?#ifSimpleDecl
	| 'if' '(' testExpression ')' bloc elseStatement? 	#ifCompose;

elseStatement:
	'else' ifStatement					#elseIF
	| 'else' instructions 					#elseSimple
	| 'else' bloc						#elseCompose;

testExpression:
	expression						#testExpr
	| testExpression SIGNELOGIQUE testExpression		#testExprLogique
	| testExpression SIGNECOMPARAISON testExpression	#testExprCompar;
	
expression : ADDSOUS expression					#expressionUnaire
			| expression MULTDIV expression		#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'			#parenthese
			| ADDSOUS? valeur 			#val;
		
valeur : 
	 ID'('parametresEffectifs')'					#appel	
	|ID 								#variable
	|INT								#int;


ESPACE : [ \n\t\r] -> skip;

MULTDIV : [*/];
ADDSOUS : [+-];
SIGNECOMPARAISON : '<='
		| '>='
		| '=='
		| '!='
		| '>'
		| '<';

SIGNELOGIQUE : '&&' 
		| '||'
		| '!';

TYPE : 'int';

ID : [a-zA-Z_]+;
INT : [0-9]+ ;
