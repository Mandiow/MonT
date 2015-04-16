/*
  Coloque aqui o identificador do grupo e dos seus membros
*/
%{
#include <stdio.h>
#include "main.h"
#include <time.h>
clock_t sec;

%}

%union
{
	struct comp_tree_t *syntaxTree;
	struct comp_dict_item_t *valor_simbolo_lexico;

}



/* Declaração dos tokens da linguagem */
%token TK_PR_INT
%token<syntaxTree> TK_PR_FLOAT
%token<syntaxTree> TK_PR_BOOL
%token<syntaxTree> TK_PR_CHAR
%token<syntaxTree> TK_PR_STRING
%token<syntaxTree> TK_PR_IF
%token<syntaxTree> TK_PR_THEN
%token<syntaxTree> TK_PR_ELSE
%token<syntaxTree> TK_PR_WHILE
%token<syntaxTree> TK_PR_DO
%token<syntaxTree> TK_PR_INPUT
%token<syntaxTree> TK_PR_OUTPUT
%token<syntaxTree> TK_PR_RETURN
%token<syntaxTree> TK_PR_STATIC
%token<syntaxTree> TK_PR_CONST
%token<syntaxTree> TK_OC_LE
%token<syntaxTree> TK_OC_GE
%token<syntaxTree> TK_OC_EQ
%token<syntaxTree> TK_OC_NE
%token<syntaxTree> TK_OC_AND
%token<syntaxTree> TK_OC_OR
%token<syntaxTree> TK_LIT_INT
%token<syntaxTree> TK_LIT_FLOAT
%token<syntaxTree> TK_LIT_FALSE
%token<syntaxTree> TK_LIT_TRUE
%token<syntaxTree> TK_LIT_CHAR
%token<syntaxTree> TK_LIT_STRING
%token<valor_simbolo_lexico> TK_IDENTIFICADOR
%token TOKEN_ERRO


/*Declaração dos tipos das estruturas*/
%type<syntaxTree> start
%type<syntaxTree> programa
%type<syntaxTree> declaracao_global	
%type<syntaxTree> qualificador_tipo
%type<syntaxTree> declarar_funcao
%type<syntaxTree> declaracao_local
%type<syntaxTree> bloco_comando
%type<syntaxTree> comando
%type<syntaxTree> ID
%type<syntaxTree> atribuicao
%type<syntaxTree> expressao_controle
%type<syntaxTree> controle_fluxo
%type<syntaxTree> chamada_funcao
%type<syntaxTree> operador_logico
%type<syntaxTree> operador_aritmetico
%type<syntaxTree> expressao
%type<syntaxTree> tem_operador
%type<syntaxTree> retorno
%type<syntaxTree> entrada
%type<syntaxTree> saida
%type<syntaxTree> '%'
%type<syntaxTree> '+'
%type<syntaxTree> '-'
%type<syntaxTree> '>'
%type<syntaxTree> '<'
%type<syntaxTree> '*'
%type<syntaxTree> '/'
%type<syntaxTree> ';'
%type<syntaxTree> '{'
%type<syntaxTree> '}'

%type<syntaxTree> literal
%type<valor_simbolo_lexico> parametros
%type<valor_simbolo_lexico> parametros_vazio
%type<valor_simbolo_lexico> lista_parametros

%nonassoc LOWER_THAN_ELSE
%nonassoc TK_PR_ELSE

%%
/* Regras (e ações) da gramática */
/* $$ = start 
   $1 = programa
*/
start: programa {$$ = createNode(AST_PROGRAMA,NULL);printf("%d, final\n",sec = clock());gv_create_initial_tree($$);gv_create_subtree($$,$1); syntaxTree = $$; printf("OI!\n");}
	;
/* $$ = programa 
   $1 = declaracao_global
   $2 = ';' 
   $3 = programa(eu acho, não sei, muito confuso eu sei =.=)
   $1 = declarar_funcao
   $2 = programa
   sim, demorei algum bom tempo pra me tocar disso =.=
*/
programa
	: declaracao_global ';' programa {$$=$1;}
	| declarar_funcao programa {$$ = $1;printf("%d, %s\n",sec = clock(),$1->tableItem->key);gv_create_subtree($$,$2);}
	| {$$ = NULL;} 
	;

declaracao_global
	: especificador_tipo TK_IDENTIFICADOR '[' TK_LIT_INT ']'
	| especificador_tipo TK_IDENTIFICADOR 
	| TK_PR_STATIC especificador_tipo  TK_IDENTIFICADOR '[' TK_LIT_INT ']'
	;

declarar_funcao	
	: especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' '{' bloco_comando '}' {$$ = createNode(AST_FUNCAO,$2);appendNewNode($$,$7);}
	| TK_PR_STATIC especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' '{' bloco_comando '}'
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
	| TK_PR_STATIC especificador_tipo TK_IDENTIFICADOR 
	| TK_PR_STATIC especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor 
	| TK_PR_STATIC qualificador_tipo especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor 
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

qualificador_tipo
	: TK_PR_CONST
	;




bloco_comando
	:  comando ';' bloco_comando {$$ = $1};
	|  comando {$$ = $1;}
	| ';' {$$ = $1;}
	|{$$ = NULL;}
	;

	

comando
	: retorno 
	| atribuicao
	| declaracao_local 
    | controle_fluxo 
	| '{' bloco_comando '}' { $$ = createNode(AST_BLOCO, NULL); gv_create_subtree($$,$2);}
	| entrada
	| chamada_funcao 
	| saida 
	;

parametros_vazio
	: parametros
	| {$$ = NULL;}
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
	| {$$ = NULL;}
	;




expressao_controle
	: expressao operador_logico expressao expressao_controle
	| {$$ = NULL;}
	;


%%
