grammar expr;

programme : fonction+;

fonction : TYPE ID'('parametresFormels')' bloc;
bloc: '{'declarations* instructions*'}';

parametresFormels : (parametre(','parametre)*)*;

parametre : TYPE ID;

parametresEffectifs : (expression(','expression)*)*;

declarations :
			TYPE ID';' 					#declarationSimple
			| TYPE ID '=' expression';'			#declarationAvecAffectation
			| TYPE ID'['INT']'';'				#declarationTabSimple
			| TYPE ID'['INT']' '=' expressionTab';'		#declarationTabAvecAffectation;

instructions : expression';'				#expressionSeule
			| ID '=' expression';'			#affectation			
			| ID'['expression']' '=' expression';'	#affectationCaseTab
			| 'return' expression';'		#return
			| ifStatement					#instrIF
			| whileStatement				#instrWHILE
			| bloc							#blocSimple;


ifStatement:
	'if' '(' testExpression ')' instructions elseStatement?		#ifInstr
	| 'if' '(' testExpression ')' declarations elseStatement?	#ifSimpleDecl;


elseStatement:
	'else' ifStatement						#elseIF
	| 'else' instructions 					#elseSimple;

whileStatement:
	'while' '(' testExpression ')' instructions		#whileInstr;


testExpression:
	'!' testExpression									#not
	| '(' testExpression ')'							#testExprPar
	| expression SIGNECOMPARAISON expression			#testExprCompar
	| testExpression SIGNELOGIQUE testExpression		#testExprLogique
	| expression										#testExpressionSimple;

	
expression : ADDSOUS expression					#expressionUnaire
			| expression MULTDIV expression		#expressionMultDiv
			| expression ADDSOUS expression		#expressionAddSous
			| '('expression')'			#parenthese
			| ADDSOUS? valeur 			#val;

expressionTab :		'{'(expression(','expression)*)*'}';
valeur : 
	 ID'('parametresEffectifs')'					#appel	
	|ID 								#variable
	|INT								#int
	|ID'['expression']'						#valCaseTab;


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

TYPE : 'int';

ID : [a-zA-Z_]+;
INT : [0-9]+ ;
