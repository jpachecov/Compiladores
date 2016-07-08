%{
#include <iostream>
#include <fstream>
#include "pila/stack.cpp"
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include "parser.tab.h"

using namespace std;
/*
* Este archivo crea un analizador lexico para python
* escrito en C++.
* Equipo Untracked
* Medina Santamaria Claudia Paola
* Miranda Sanchez Luis Eduardo
* Pacheco Avila Jean Pierre 
*/

/*
* Pila para guardar enteros que representan los espacios
* y los espacios del tabulador
*/
stack<int> pila;


int start=0;
int numLineas=1;
int tabinicial=1;
int comilla=0;
int number = 1;
int salida = 0;
int identinicial=1;
int sacandodedents=0;
int tabInicial();
void escribe(string);
int newL=1;
int dedent=0;
/*
* Cadena que ira al archivo de texto.
*/
string tofile;
%}

%option noyywrap
%option outfile="pylex.cpp"

IDENTIFIER [_a-zA-Z][_a-zA-Z0-9]*
NUMBER -?([0-9]+|[0-9]*\.[0-9]+)|-?([1-9]+\.([0-9]*[e|E][0-9]+))
ESPACIO [[:blank:]]
CADENA \"[^+\"]*\"

%%
<<EOF>>         { escribe("FIN ");
                  if(pila.size()!=0 && pila.peek()!=0){

                    pila.create();
                    pila.push(0);
                    yyless(0);
                    escribe("DEDENTF");
                    return(DEDENT);
                  }
                 static int once = 0; 
	return once++ ? 0 : NEWLINE;
                }

{CADENA}       {   
		escribe(" STRING ");
		yylval.val_cad = yytext;
		return (STRING);
                }

\n              { 
                  if(!dedent)
                    numLineas++;
                  
                  if(start){
                    start=0;newL=0;yyless(0);
                    escribe("NEWLINE1\n");
                    return NEWLINE;
                    //start=0;
                  }
                  if (pila.size() == 0){                    
                  }else{
                    if(pila.peek() == 0 && newL==1){
                      escribe("NEWLINE2\n");newL=0;
                      return NEWLINE;
                    }else{ 
                      if (pila.peek() != 0){
                        pila.pop();
                        yyless(0);
                        if(!start){
                          escribe("DEDENT1 ");
                          dedent=1;
                          return DEDENT;
                          //dedent=1;
                        }
                      }
                    }
                  }
                  //newL=0;
                  //start =0;
                  if(comilla){
                    cerr << "4.-Error de cadena "<< numLineas << "\n";
                    exit(0);
                  }
                }

\n[\t]+/[[:alnum:]]         {  
                /*Imprimir un solo NEWLINE*/
                  if(newL==1){ 
 			newL = 0;
			yyless(0);
                        escribe("NEWLINE3\n");                   
			return NEWLINE;
                  }
                   // newL=0; ya imprimio un newline y se reinicia
                  if(!dedent)
                    numLineas++;
                  /*manda error de identacion en la primera linea*/
                  if(tabinicial){
                    cerr << "2.- Error de identacion en la linea "<< numLineas << "\n";
                    exit(0);
                  }
                  /*Error para las cadenas*/
                  if(comilla){
                    cerr << "3.-Error de cadena "<< numLineas << "\n";
                    exit(0);
                  }
                  start=1;
                  if (yyleng == 1){
                    if (pila.peek() != 0){
                        pila.pop();
                        if (pila.peek() > ((yyleng-1)*8+1) && pila.peek() != 0)
                        yyless(0);
                        escribe("DEDENT2 ");
                        return DEDENT;
                    }
                  } else{
                    if (pila.peek() < ((yyleng-1)*8+1) && newL ==0){
                        pila.push(((yyleng-1)*8+1));
                        dedent = 0;                          
			escribe("INDENT1 ");
                        return INDENT;
                        //dedent=0;
                    } else if (pila.peek() > ((yyleng-1)*8+1)){
                        pila.pop();
                        if(pila.peek() == 0){
                          cerr << "1.-Error de identacion en la linea "<< numLineas<< "\n";
                          exit(0);
                        }else{
                          yyless(0);
                          escribe("DEDENT3 ");
                          dedent = 1;
                          return DEDENT;
                          //dedent=1;
                        }
                    }
                    /*si no hay identacion*/
                    if(pila.peek() == 0){
                      start=0;
                    }

                    if(pila.peek() < ((yyleng-1)*8+1)){
                      cerr << "Error de identacion en la linea "<< numLineas << "\n";
                      exit(0);
                    }  
                  }
                }

\n{ESPACIO}+/[[:alnum:]]   {  
                /*Imprimir un solo NEWLINE*/
                  if(newL==1){
		    newL=0;
		    yyless(0); 
	            escribe("NEWLINE4\n");
                    return NEWLINE;
                  }
                  //newL=0;ya imprimio un newline y se reinicia
                  if(!dedent)
                    numLineas++;
                  /*manda error de identacion en la primera linea*/
                  if(tabinicial){
                    cerr << "2.- Error de identacion en la linea "<< numLineas << "\n";
                    exit(0);
                  }
                  /*Error para las cadenas*/
                  if(comilla){
                    cerr << "3.-Error de cadena "<< numLineas << "\n";
                    exit(0);
                  }
                  start=1;
                  if (yyleng == 1){
                    if (pila.peek() != 0){
                        pila.pop();
                        if (pila.peek() > yyleng && pila.peek() != 0)
                        yyless(0);
                        escribe("DEDENT5 ");
                        return DEDENT;
                    }
                  } else{
                    if (pila.peek() < yyleng && newL ==0){
                        pila.push(yyleng);
                        escribe("INDENT2 ");
                        dedent = 0;
			return INDENT; 
                        //dedent=0;
                    } else if (pila.peek() > yyleng){
                        pila.pop();
                        if(pila.peek() == 0){
                          cerr << "1.-Error de identacion en la linea "<< numLineas<< "\n";
                          exit(0);
                        }else{
                          yyless(0);
                          escribe("DEDENT6 ");
                          dedent=1;
                          return DEDENT;
                          //dedent=1;
                        }
                    }
                    /*si no hay identacion*/
                    if(pila.peek() == 0){
                      start=0;
                    }

                    if(pila.peek() < yyleng){
                      cerr << "Error de identacion en la linea "<< numLineas << "\n";
                      exit(0);
                    }  
                  }
                }
                
\t              { 
                  if(tabinicial){
                    cerr << "Error de identacion en la linea "<< numLineas << "\n";
                    exit(0);
                  }
                }
{ESPACIO}       { 
                  if(tabinicial){
                    cerr << "Error de identacion en la linea "<< numLineas << "\n";
                    exit(0);
                  }
                }

":"             {if(tabInicial()) {escribe(": ");return(DOSP);}}
";"             {if(tabInicial()) {escribe("; ");return(SEMICOLON);}}
","             {if(tabInicial()) {escribe(", ");return(COMA);}}
"and"           {if(tabInicial()) {escribe("AND ");return(AND);}}
"break"         {if(tabInicial()) {escribe("BREAK ");return(BREAK);}}
"continue"      {if(tabInicial()) {escribe("CONTINUE ");return(CONTINUE);}}
"global"        {if(tabInicial()) {escribe("GLOBAL ");return(GLOBAL);}}
"def"           {if(tabInicial()) {escribe("DEF ");return(DEF);}}
"del"           {if(tabInicial()) {escribe("DEL ");return(DEL);}}
"elif"          {if(tabInicial()) {escribe("ELIF ");return(ELIF);}}
"else"          { 
                 //if(tabInicial()) {escribe("ELSE ");return(ELSE);}
                escribe("ELSE ");
                return(ELSE);

                }
"for"           {if(tabInicial()) {escribe("FOR ");return(FOR);}}
"if"            {if(tabInicial()) {escribe("IF ");return(IF);}}
"in"            {if(tabInicial()) {escribe("IN ");return(IN);}}
"is"            {if(tabInicial()) {escribe("IS ");return(IS);}}
"not"           {if(tabInicial()) {escribe("NOT ");return(NOT);}}
"or"            {if(tabInicial()) {escribe("OR ");return(OR);}}
"print"         {if(tabInicial()) {escribe("PRINT ");return(PRINT);}}
"return"        {if(tabInicial()) {escribe("RETURN ");return(RETURN);}}
"while"         {if(tabInicial()) {escribe("WHILE ");return(WHILE);}}
{IDENTIFIER}    { 
                  if(!number && newL){
                    cerr << "1. Error numerico en la linea "<< numLineas << "\n";
                    exit(0);
                  }
                  if(tabInicial()){
		    escribe("NAME "); 
			yylval.val_ident = yytext;
                    return(NAME);
                    }
                }
{NUMBER}        {number=1;
                  if(number){
                    if(tabInicial()){ 
      			escribe("NUMBER ");
      			number = 0;
			
			string numero (yytext);
			string f (".");
			if(numero.find(f) != std::string::npos){
			//asignamos valor flotante
			float valorf = atof(yytext);
			yylval.numero.tipo = FLOTANTE;
			yylval.numero.valor.valf = valorf;
			} else {
			//asignamos valor entero
			int valori = atoi(yytext);
			yylval.numero.tipo = 0;
			yylval.numero.valor.vali = valori;
			}
                        //number = 0;
      			return(NUMBER);
                        }

                 //   number=0;
                  }else{
                    cerr << "2. Error numerico en la linea "<< numLineas << "\n";
                    exit(0);
                  }

                }
"+"       {if(tabInicial()) {escribe("+ ");return(MAS);}}
"-"       {if(tabInicial()) {escribe("- ");return(MENOS);}}
"*"       {if(tabInicial()) {escribe("* ");return(POR);}}
"/"       {if(tabInicial()) {escribe("/ ");return(DIV);}}
"+="      {if(tabInicial()) {escribe("+= ");return(MASIGUAL);}}
"-="      {if(tabInicial()) {escribe("-= ");return(MENOSIGUAL);}}
"*="      {if(tabInicial()) {escribe("*= ");return(PORIGUAL);}}
"/="      {if(tabInicial()) {escribe("/= ");return(DIVIGUAL);}}
"//="     {if(tabInicial()) {escribe("//= ");return(DIVENTIGUAL);}}
"&="      {if(tabInicial()) {escribe("&= ");return(YIGUAL);}}
"%="      {if(tabInicial()) {escribe("%= ");return(MODIGUAL);}}
"^="      {if(tabInicial()) {escribe("^= ");return(XORIGUAL);}}
"|="      {if(tabInicial()) {escribe("|= ");return(OIGUAL);}}
"<<="     {if(tabInicial()) {escribe("<<= ");return(CIIGUAL);}}
"<<"      {if(tabInicial()) {escribe("<< ");return(CORIZQ);}}
">>"      {if(tabInicial()) {escribe(">> ");return(CORDER);}}
">>="     {if(tabInicial()) {escribe(">>= ");return(CDIGUAL);}}
"%"       {if(tabInicial()) {escribe("% ");return(MOD);}}
"**"      {if(tabInicial()) {escribe("** ");return(POW);}}
"//"      {if(tabInicial()) {escribe("// ");return(DIVENT);}}
"**="     {if(tabInicial()) {escribe("**= ");return(POWIGUAL);}}
"&"       {if(tabInicial()) {escribe("& ");return(ANDB);}}
"|"       {if(tabInicial()) {escribe("| ");return(ORB);}}
"^"       {if(tabInicial()) {escribe("^ ");return(XOR);}}
"<"       {if(tabInicial()) {escribe("< ");return(LESS);}}
">"       {if(tabInicial()) {escribe("> ");return(MORE);}}
"<="      {if(tabInicial()) {escribe("<= ");return(LIGUAL);}}
">="      {if(tabInicial()) {escribe(">= ");return(MIGUAL);}}
"=="      {if(tabInicial()) {escribe("== ");return(EQUAL2);}}
"="       {if(tabInicial()) {escribe("= ");return(EQUAL);}}
"!="      {if(tabInicial()) {escribe("!= ");return(DIF1);}}
"<>"      {if(tabInicial()) {escribe("<> ");return(DIF2);}}

"("      {if(tabInicial()) {escribe("( ");return(PARIZQ);}}
")"      {if(tabInicial()) {escribe(") ");return(PARDER);}}
"{"      {if(tabInicial()) {escribe("{ ");return(KEYIZQ);}}
"}"     {if(tabInicial()) {escribe("} ");return(KEYDER);}}
"["      {if(tabInicial()) {escribe("[ ");return(CLASPIZQ);}}
"]"      {if(tabInicial()) {escribe("] ");return(CLASPDER);}}

. {escribe(" W ");}
%%
int tabInicial(){
  number=1;
  newL=1;
  if(!start){
    tabinicial=0;
    pila.push(0);
  }
  if(comilla){
    return 0;
  
  }
  return 1;
}
void escribe(string cadena){
  ofstream archivo;
  archivo.open ("salida.txt",std::ofstream::app);
  archivo << cadena;
  archivo.close();
}
