/*
  Coloque aqui o identificador do grupo e dos seus membros
*/
%{
#include <stdio.h>
#include "cc_dict.h"

%}

%union
{
	struct comp_dict_item_t *valor_simbolo_lexico;
}



/* Declaração dos tokens da linguagem */
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
%token TK_PR_IF
%token TK_PR_THEN
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_DO
%token TK_PR_INPUT
%token TK_PR_OUTPUT
%token TK_PR_RETURN
%token TK_PR_STATIC
%token TK_PR_CONST
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_LIT_CHAR
%token TK_LIT_STRING
%token TK_IDENTIFICADOR
%token TOKEN_ERRO




%nonassoc LOWER_THAN_ELSE
%nonassoc TK_PR_ELSE

%%
/* Regras (e ações) da gramática */


programa
	: declaracao_global programa
	| declarar_funcao programa
	| /* NADA */
	;

declaracao_global
	: especificador_tipo TK_IDENTIFICADOR '[' TK_LIT_INT ']' ';' 
	| especificador_tipo TK_IDENTIFICADOR ';'
	| especificador_classe_armazenamento especificador_tipo  TK_IDENTIFICADOR '[' TK_LIT_INT ']' ';'
	;

literal
	: TK_LIT_INT
	| TK_LIT_FLOAT
	| TK_LIT_FALSE
	| TK_LIT_TRUE
	| TK_LIT_CHAR
	| TK_LIT_STRING
	;

especificador_tipo
	: TK_PR_INT
	| TK_PR_FLOAT
	| TK_PR_BOOL
	| TK_PR_CHAR
	| TK_PR_STRING
	;

declaracao_local
	: especificador_tipo TK_IDENTIFICADOR  
	| especificador_tipo TK_IDENTIFICADOR TK_OC_LE valor 
	| especificador_classe_armazenamento especificador_tipo TK_IDENTIFICADOR 
	| especificador_classe_armazenamento especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor 
	| especificador_classe_armazenamento qualificador_tipo especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor 
	| qualificador_tipo especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor 
	;

valor
	: literal
	| TK_IDENTIFICADOR
	;

ID
	: TK_IDENTIFICADOR 
	| TK_IDENTIFICADOR  '[' expressao ']' 
	;





atribuicao
	: ID '=' '-' expressao
	| ID '=' expressao
	;


retorno
	: TK_PR_RETURN expressao 
	| TK_PR_RETURN 
	;

especificador_classe_armazenamento
	:TK_PR_STATIC
	;

qualificador_tipo
	: TK_PR_CONST
	;




bloco_comando
	:  comando ';' bloco_comando 
	|  comando
	| ';' 
	|
	;

	

comando
	: retorno 
	| atribuicao
	| declaracao_local 
    | controle_fluxo 
	| '{' bloco_comando '}' 
	| entrada
	| chamada_funcao 
	| saida 
	;

parametros_vazio
	: parametros
	|
	;

parametros
	: lista_parametros ',' parametros
	| lista_parametros
	;
	
lista_parametros 
	: especificador_tipo TK_IDENTIFICADOR 
	| qualificador_tipo especificador_tipo TK_IDENTIFICADOR 
	;

entrada
	: TK_PR_INPUT expressao "=>" expressao 
	;

saida
	: TK_PR_OUTPUT lista_expressoes	
	;

lista_vazia
	: lista_expressoes
	|
	;

lista_expressoes
	: expressao mais_de_uma 
	;

mais_de_uma
	: ',' lista_expressoes
	|
	;


controle_fluxo
	: TK_PR_IF '(' expressao_controle ')'  TK_PR_THEN comando TK_PR_ELSE comando
	| TK_PR_IF '(' expressao_controle ')'  TK_PR_THEN comando %prec LOWER_THAN_ELSE
	| TK_PR_WHILE '(' expressao_controle ')' TK_PR_DO comando
	| TK_PR_DO comando TK_PR_WHILE '(' expressao_controle ')'
	;

declarar_funcao	
	: especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' '{' bloco_comando '}'
	| especificador_classe_armazenamento especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' '{' bloco_comando '}'
	;






chamada_funcao
	: TK_IDENTIFICADOR  '(' lista_vazia ')' 
	;

operador_aritmetico
	: '+'
	| '-'
	| '*'
	| '/'
	| '%'
	;

operador_logico
	: TK_OC_LE
	| TK_OC_GE
	| TK_OC_EQ
	| TK_OC_NE
	| TK_OC_AND
	| TK_OC_OR
	| '<'
	| '>'
	;
	
expressao 
	: literal tem_operador
	| ID tem_operador
	| chamada_funcao tem_operador
	;

tem_operador
	: operador_aritmetico expressao
	| operador_aritmetico '(' expressao ')'
	|
	;




expressao_controle
	: expressao operador_logico expressao expressao_controle
	| 
	;


%%
