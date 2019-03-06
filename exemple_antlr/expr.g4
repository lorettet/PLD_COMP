grammar expr;

axiome : expr ; 
expr : expr '+' expr
     | INT
     ;

INT : [0-9]+ ;
