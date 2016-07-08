%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "composite-visitor/MASTBuilder.h"
#include <iostream>
#define YYDEBUG 1
using namespace std;
extern FILE *yyin;
int yylex(void);
void yyerror(const char *);

MASTBuilder* mast= new MASTBuilder();
stack<Nodo*> listaStmt;
stack<Nodo*> stmtList;
Nodo* raiz;

%}

%code requires {
#include "composite-visitor/clases.hpp"
#define FLOTANTE 1
#define ENTERO 0
}
%union{
	struct envoltura {
		union {
		  int vali;
		  float valf;
		}valor;
		int tipo;
	} numero;

	char* val_cad;
	char* val_ident;
	Nodo* n;
}


%token COMA 
%token DOSP 
%token SEMICOLON   
%token AND 
%token ANDB
%token BREAK
%token CONTINUE
%token GLOBAL
%token DEF
%token DEL
%token ELIF
%token ELSE
%token FOR
%token IF
%token IN
%token IS
%token NOT
%token OR
%token ORB
%token PRINT
%token RETURN
%token WHILE
%token <val_ident> NAME
%token <numero> NUMBER
%token PUNTO
%token MAS
%token MENOS
%token POR
%token DIV
%token MASIGUAL
%token MENOSIGUAL
%token PORIGUAL
%token DIVIGUAL
%token DIVENTIGUAL
%token YIGUAL
%token MODIGUAL
%token XORIGUAL
%token OIGUAL
%token CIIGUAL
%token CORIZQ
%token CORDER
%token CDIGUAL
%token MOD
%token COUT
%token DIVENT
%token POWIGUAL

%token POW

%token XOR
%token LESS
%token MORE
%token LIGUAL
%token MIGUAL
%token EQUAL2
%token EQUAL
%token DIF1
%token DIF2
%token PARIZQ
%token PARDER
%token KEYIZQ
%token KEYDER
%token CLASPIZQ
%token CLASPDER
%token DEDENT
%token INDENT
%token <val_cad> STRING
%token NEWLINE
%token EOFF

 
%start file_input
%type <n> file_input lista_entrada
%type <n> stmt simple_stmt
%type <n> small_stmt expr_stmt augassign print_stmt
%type <n> flow_stmt return_stmt compound_stmt if_stmt lista_elif_test_dosp_suite while_stmt
%type <n> for_stmt suite lista_stmt test or_test lista_or_and_test and_test lista_and_not_test
%type <n> not_test comparison lista_comp_op_expr comp_op expr lista_or_xor_expr xor_expr 
%type <n> lista_xor_and_expr and_expr lista_and_shift_expr shift_expr
%type <n> lista_corrimiento lista_shift_expr arith_expr lista_mas_menos lista_mm_term term lista_por_div_mod_divent lista_term factor
%type <n> signo power atom

%%


file_input: 
	lista_entrada {
        Nodo* lista = mast->bStmtListNode();
        while(listaStmt.size()!=0){
        lista->add(listaStmt.pop());
	}
        raiz = lista;
}
;

lista_entrada:                   {}
        |NEWLINE lista_entrada   {}
	| stmt lista_entrada     {listaStmt.push($1);}
;

stmt:
          simple_stmt   {$$=$1;}
	| compound_stmt {$$=$1;}
;

simple_stmt: small_stmt NEWLINE {$$=$1;}
;

small_stmt:
          expr_stmt  {$$ = $1;}
	| print_stmt {$$ = $1;}
	| flow_stmt  {}
;


expr_stmt: test               {$$=$1;}
	| test augassign test {
                $2->setFirstChild($1);
                $2->setLastChild($3);
                $$ = $2;
        
                } 
	| test EQUAL test {
                Nodo* a= mast->bAsignacionNode();
                a->setFirstChild($1);
                a->setLastChild($3);
                $$ = a;
                }
;

augassign:
          MASIGUAL   {$$ = mast->bPlusEqualNode();}
	| MENOSIGUAL {$$ = mast->bMinusEqualNode();}
	| PORIGUAL   {$$ = mast->bTimesEqualNode();}
	| DIVIGUAL   {$$ = mast->bDivEqualNode();}
	| MODIGUAL   {$$ = mast->bModEqualNode();}
	| YIGUAL     {$$ = mast->bAndIgualNode();}
	| OIGUAL     {$$ = mast->bOrIgualNode();}
	| XORIGUAL   {$$ = mast->bXorIgualNode();}
	| CIIGUAL    {$$ = mast->bCorIzqIgualNode();}
	| CDIGUAL    {$$ = mast->bCorDerIgualNode();}
	| POWIGUAL   {$$ = mast->bPowIgualNode();}
	| DIVENTIGUAL {$$ = mast->bDiventIgualNode();}
;

print_stmt: PRINT test {Nodo* n = mast->bPrintNode();
                        n -> addRightChild($2);
                        $$ = n;
                        }
;

flow_stmt:
	BREAK         {}
	| CONTINUE    {} 
	| return_stmt {}
;

return_stmt:
	RETURN test {}
	| RETURN    {}
;


compound_stmt:
	if_stmt      {$$ = $1;}
	| while_stmt {$$ = $1;}
	| for_stmt   {$$ = $1;}
;

if_stmt:
	IF test DOSP suite lista_elif_test_dosp_suite {

                Nodo* iff = mast->bIFNode();
                iff->add($2);
                iff->add($4);
                if($5 != NULL){
                iff->add($5);
                } else {iff->add(NULL);}
       
                
$$ = iff;
        }
	|IF test DOSP suite lista_elif_test_dosp_suite ELSE DOSP suite {
                 Nodo* iff = mast->bIFNode();
                if($5 == NULL){

                iff->add($2);
                iff->add($4);
                iff->add($8);

                } else {
                $4->add($5);
                iff->add($2);
                iff->add($4);
                iff->add($8);
                }
                $$ = iff;
  
              }
; 


lista_elif_test_dosp_suite: { $$ = NULL;}
	| ELIF test DOSP suite lista_elif_test_dosp_suite {
                                
                Nodo* iff = mast->bIFNode();
                iff->add($2);
                iff->add($4);
                $$ = iff;
                }
;

while_stmt:
	WHILE test DOSP suite { 

                Nodo* n = mast->bWHILENode();
                n->add($2);
                n->add($4);
                $$ = n;   
                   }
;

for_stmt:
	FOR expr IN test DOSP NEWLINE INDENT print_stmt NEWLINE DEDENT {
                Nodo* n = mast->bFORNode();
                n->add($2);
                n->add($4);
                n->add($8);
                $$ = n;
                }
;

suite:
	simple_stmt {
                stmtList.push($1); 
                 Nodo *s = mast->bStmtListNode();
                while(stmtList.size() != 0){
                Nodo* k = stmtList.pop();
                s->add(k);
                }
        $$ = s;

        }
	| NEWLINE INDENT lista_stmt DEDENT {
               Nodo *s = mast->bStmtListNode();
                while(stmtList.size() != 0){
                Nodo* k = stmtList.pop();
                s->add(k);
                }
        $$ = s;
                }
;

lista_stmt:
	stmt {
                stmtList.push($1);
                
        }
	|stmt lista_stmt {
                stmtList.push($1);

        }
;


test:
	or_test IF or_test ELSE test {}
	|or_test { $$=$1;}
;

or_test:  and_test {$$ = $1;}
	| and_test lista_or_and_test {}
;

lista_or_and_test: OR and_test {}
	| OR and_test lista_or_and_test {}
;

and_test: not_test {$$ = $1;}
        | not_test lista_and_not_test {}
;

lista_and_not_test: AND not_test {}
	| AND not_test lista_and_not_test {}
;

not_test:
	NOT not_test {}
	|comparison {$$=$1;}
;

comparison: expr  {$$=$1;}
	| expr lista_comp_op_expr {
                $2->setFirstChild($1);
                $$ = $2;

        }
;


lista_comp_op_expr: comp_op expr {
                $1->setLastChild($2);
                $$ = $1;
        }
	| comp_op expr lista_comp_op_expr {
                $3 -> setFirstChild($2);
                $1 -> setLastChild($3);

        }
;

comp_op: 
	LESS         {$$ = mast -> bLessNode();}
	|MORE        {$$ = mast -> bMoreNode();}
	|EQUAL2      {$$ = mast->bEqual2Node();}
	|MIGUAL      {$$ = mast -> bMoreEqualNode();}
	|LIGUAL      {$$ = mast -> bLessEqualNode();}
	|DIF2        {$$ = mast -> bNotEqualNode();}
	|DIF1        {$$ = mast -> bNotEqualNode();}
	| IN         {} 
	| NOT IN     {}
	| IS         {}
	|IS NOT      {}
;

expr:    xor_expr {$$=$1;}
	|xor_expr lista_or_xor_expr {}
;

lista_or_xor_expr:  ORB xor_expr {}
	| ORB xor_expr lista_or_xor_expr {}
;

xor_expr: and_expr {$$=$1;}
	| and_expr lista_xor_and_expr {}
;

lista_xor_and_expr: XOR and_expr {}
	| XOR and_expr lista_xor_and_expr {}
;

and_expr: shift_expr {$$ = $1;}
	| shift_expr lista_and_shift_expr {}
;

lista_and_shift_expr: ANDB shift_expr {}
	| ANDB shift_expr lista_and_shift_expr {}
;

shift_expr: arith_expr {$$ = $1;}
	| arith_expr lista_shift_expr {}
;

lista_corrimiento:
	CORIZQ   {}
	| CORDER {}
;

lista_shift_expr: lista_corrimiento arith_expr          {}
	| lista_corrimiento arith_expr lista_shift_expr {}
;



arith_expr:  
         term {$$ = $1;}
       | term lista_mm_term {
                $2 ->setFirstChild($1);
                if($2->tipo.compare("string") == 0){
                        if($1->tipo.compare("string")!=0) $2->tipo = "error";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop";
                }
                if($2->tipo.compare("int") == 0){
                        if($1->tipo.compare("string") == 0) $2->tipo = "error";
                        if($1->tipo.compare("float") == 0) $2->tipo = "float";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop"; 
 
                }
                if($2->tipo.compare("float") == 0){
                        if($1->tipo.compare("string") == 0) $2->tipo = "error";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop";
 
                }
                if($2->tipo.compare("var") == 0){
                        if($1->tipo.compare("error") == 0) $2->tipo = "error";
                        $2->tipo = "varop";
 
                }
                $$ = $2;
              
                        }
;

lista_mas_menos:
	MAS    {$$ = mast->bPlusNode();}
	|MENOS {$$ = mast->bMinusNode();}
;

lista_por_div_mod_divent:
	POR     {$$ = mast->bTimesNode();}
	|DIV    {$$ = mast->bDivNode();}
	|MOD    {$$ = mast->bModNode();}
	|DIVENT {$$ = mast-> bDivNode();}
;


lista_mm_term: 
          lista_mas_menos term {
                
                $1->setFirstChild($2);
                $1->tipo = $2->tipo;
                $$ = $1;
                
                               }
	| lista_mas_menos term lista_mm_term {
                $3 -> setFirstChild($2);
                $1 -> setLastChild($3);
                $1->tipo = $3->tipo;
                if($3->tipo.compare("string") == 0){
                        if($2->tipo.compare("string")!=0) $1->tipo = "error";
                }
                if($3->tipo.compare("int") == 0){
                        if($2->tipo.compare("string") == 0) $1->tipo = "error";
                        if($2->tipo.compare("float") == 0) $1->tipo = "float"; 
                        
 
                }
                if($3->tipo.compare("float") == 0){
                        if($2->tipo.compare("string") == 0) $1->tipo = "error";
                        
                }
                
                }
;

term:     factor            {$$ = $1;}
	| factor lista_term {

                $2 ->setFirstChild($1);
                if($2->tipo.compare("string") == 0){
                        if($1->tipo.compare("string")!=0) $2->tipo = "error";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop";
                }
                if($2->tipo.compare("int") == 0){
                        if($1->tipo.compare("string") == 0) $2->tipo = "error";
                        if($1->tipo.compare("float") == 0) $2->tipo = "float";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop"; 
 
                }
                if($2->tipo.compare("float") == 0){
                        if($1->tipo.compare("string") == 0) $2->tipo = "error";
                        if($1->tipo.compare("var") == 0) $2->tipo = "varop";
 
                }
                if($2->tipo.compare("var") == 0){
                        if($1->tipo.compare("error") == 0) $2->tipo = "error";
                        $2->tipo = "varop";
 
                }
                $$ = $2;

               
                          }
;

lista_term: 
          lista_por_div_mod_divent factor {

                                                $1->setLastChild($2);
                                                $1->tipo = $2->tipo;
                                                $$ = $1;
                                          }
	| lista_por_div_mod_divent factor lista_term {
	    
                $3->setFirstChild($2);
                $1->setLastChild($3);
                $1->tipo = $3->tipo;
                if($3->tipo.compare("string") == 0){
                        $1->tipo = "error";
                }
                if($3->tipo.compare("int") == 0){
                        if($2->tipo.compare("string") == 0) $1->tipo = "error";
                        if($2->tipo.compare("float") == 0) $1->tipo = "float"; 
                        
 
                }
                if($3->tipo.compare("float") == 0){
                        if($2->tipo.compare("string") == 0) $1->tipo = "error";
                        
                }
                                                     }
;

factor: 
	signo factor {} 
	| power      { $$=$1;}
;

signo:
	MAS    {}
	|MENOS {}
;


power: atom {
	     $$ = $1; }
;


atom:    NAME  {
                 $$ = mast->bIDENTNode($1);

                
                }
	| NUMBER {
			if($1.tipo == FLOTANTE) {
				float n = $1.valor.valf;

                                $$ = mast->bFloatNode($1.valor.valf);

			 } else {
				int r = $1.valor.vali;
	
                                $$ = mast->bIntNode($1.valor.vali);
				}
		        
                       	
		}
	| STRING {
		$$ = mast->bStrNode($1);  			
	 }
;


%%

int main(int argc, char *argv[]){
	FILE *myfile = fopen(argv[1],"r");
	if (!myfile) {
		cout << "No existe el archivo" << endl;
		return -1;
	}

	yyin = myfile;
	if(yyparse() == 0) {
	} else {
	  cout << "Error de sintaxis \n";
          exit(1);
	}
	SemanticVisitor* pv = new SemanticVisitor(); 
        CodeVisitor* c = new CodeVisitor(pv->ts);
        raiz->Accept(pv);
        raiz->Accept(c);
        c->escribe("return 0;\n");
        c->escribe("}\n");
	

}

void yyerror(const char *error){
  cerr << error  ;
}
