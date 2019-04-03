
grammar expr;

axiome : fonction ;
fonction : type nomFonction'('parametres')' bloc;
bloc: '{'declarations* instructions*'}';
type : 'int';
nomFonction : 'main';
parametres :
		| 'void';
declarations :
			type VARIABLE';' 					#declarationSimple
			| type VARIABLE '=' expression';'	#declarationAvecAffectation;

instructions :
			VARIABLE '=' expression';'		#affectation
			| ifStatement				#instrIF
			| 'return' expression';'		#return;

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
	
expression : expression MULTDIV expression			#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'			#parenthese
			| ADDSOUS? valeur			#val;
		
valeur : VARIABLE 	#variable
	| INT		#int;

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
		| '||';

VARIABLE : [a-zA-Z]+;
INT : [0-9]+ ;
