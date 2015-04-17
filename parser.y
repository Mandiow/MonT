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
%token<valor_simbolo_lexico> TK_OC_LE
%token<valor_simbolo_lexico> TK_OC_GE
%token<valor_simbolo_lexico> TK_OC_EQ
%token<valor_simbolo_lexico> TK_OC_NE
%token<valor_simbolo_lexico> TK_OC_AND
%token<valor_simbolo_lexico> TK_OC_OR
%token<valor_simbolo_lexico> TK_OC_NOT
%token<valor_simbolo_lexico> TK_LIT_INT
%token<valor_simbolo_lexico> TK_LIT_FLOAT
%token<valor_simbolo_lexico> TK_LIT_FALSE
%token<valor_simbolo_lexico> TK_LIT_TRUE
%token<valor_simbolo_lexico> TK_LIT_CHAR
%token<valor_simbolo_lexico> TK_LIT_STRING
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
%type<syntaxTree> controle_fluxo
%type<syntaxTree> chamada_funcao
%type<syntaxTree> operador_logico
%type<syntaxTree> operador_aritmetico
%type<syntaxTree> expressao
%type<syntaxTree> tem_operador
%type<syntaxTree> retorno
%type<syntaxTree> entrada
%type<syntaxTree> saida
%type<valor_simbolo_lexico> '%'
%type<valor_simbolo_lexico> '+'
%type<valor_simbolo_lexico> '-'
%type<valor_simbolo_lexico> '>'
%type<valor_simbolo_lexico> '<'
%type<valor_simbolo_lexico> '*'
%type<valor_simbolo_lexico> '/'
%type<valor_simbolo_lexico> '='
%type<syntaxTree> ';'
%type<syntaxTree> '{'
%type<syntaxTree> '}'
%type<valor_simbolo_lexico> '!'
%type<syntaxTree> inverte
%type<valor_simbolo_lexico> literal
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
start: programa {$$ = createNode(AST_PROGRAMA,NULL);appendChildNode($$,$1);gv_create_initial_tree($$); syntaxTree = $$;}
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
	| declarar_funcao programa {$$ = $1;appendChildNode($$,$2);}
	| {$$ = NULL;} 
	;

declaracao_global
	: especificador_tipo TK_IDENTIFICADOR '[' TK_LIT_INT ']'
	| especificador_tipo TK_IDENTIFICADOR 
	| TK_PR_STATIC especificador_tipo  TK_IDENTIFICADOR '[' TK_LIT_INT ']'
	;

declarar_funcao	
	: especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' '{' bloco_comando '}' {$$ = createNode(AST_FUNCAO,$2);appendChildNode($$,$7);}
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
	: TK_IDENTIFICADOR {$$ = createNode(AST_IDENTIFICADOR,$1);}
	| TK_IDENTIFICADOR  '[' expressao ']' {$$ = createNode(AST_VETOR_INDEXADO,$1); appendChildNode($$,$3);}
	;





atribuicao
	: ID '=' inverte expressao {$$ = createNode(AST_ATRIBUICAO,$2); appendChildNode($$,$1);appendChildNode($$,$3);appendChildNode($3,$4);}
	| ID '=' expressao {$$ = createNode(AST_ATRIBUICAO,$2); appendChildNode($$,$1);appendChildNode($$,$3);}
	;
inverte
	: '-' {$$ = createNode(AST_ARIM_INVERSAO,NULL);}
	;


retorno
	: TK_PR_RETURN expressao 
	| TK_PR_RETURN 
	;

qualificador_tipo
	: TK_PR_CONST
	;




bloco_comando
	:  comando ';' bloco_comando {$$ = $1; appendChildNode($$,$3);} 
	|  comando {$$ = $1;}
	| ';' {$$ = $1;}
	|{$$ = NULL;}
	;

	

comando
	: retorno 
	| atribuicao
	| declaracao_local 
    | controle_fluxo {$$ = $1;}
	| '{' bloco_comando '}' { $$ = createNode(AST_BLOCO, NULL);appendChildNode($$,$2);}
	| entrada {$$ = $1;}
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
	: TK_PR_INPUT expressao '=''>' expressao {$$ = createNode(AST_INPUT, NULL); appendChildNode($$,$2);appendChildNode($$,$5);}
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
	: TK_PR_IF '(' expressao ')'  TK_PR_THEN comando TK_PR_ELSE comando {$$ = createNode(AST_IF_ELSE,NULL); appendChildNode($$,$3);appendChildNode($$,$6);appendChildNode($$,$8);}
	| TK_PR_IF '(' expressao ')'  TK_PR_THEN comando %prec LOWER_THAN_ELSE {$$ = createNode(AST_IF_ELSE,NULL); appendChildNode($$,$3);appendChildNode($$,$6);}
	| TK_PR_WHILE '(' expressao ')' TK_PR_DO comando {$$ = createNode(AST_WHILE_DO,NULL); appendChildNode($$,$3);appendChildNode($$,$6);}
	| TK_PR_DO comando TK_PR_WHILE '(' expressao ')' {$$ = createNode(AST_DO_WHILE,NULL); appendChildNode($$,$2);appendChildNode($$,$5);}
	;







chamada_funcao
	: TK_IDENTIFICADOR  '(' lista_vazia ')' 
	;

operador_aritmetico
	: '+' {$$ = createNode(AST_ARIM_SOMA, NULL);}
	| '-' {$$ = createNode(AST_ARIM_SUBTRACAO, NULL);}
	| '*' {$$ = createNode(AST_ARIM_MULTIPLICACAO, NULL);}
	| '/' {$$ = createNode(AST_ARIM_DIVISAO, NULL);}
	| '%' {$$ = createNode(AST_LOGICO_COMP_LE, NULL);}
	;

operador_logico
	: TK_OC_LE  {$$ = createNode(AST_LOGICO_COMP_LE, NULL);}
	| TK_OC_GE  {$$ = createNode(AST_LOGICO_COMP_GE, NULL);}
	| TK_OC_EQ  {$$ = createNode(AST_LOGICO_COMP_IGUAL, NULL);}
	| TK_OC_NE  {$$ = createNode(AST_LOGICO_COMP_DIF, NULL);}
	| TK_OC_AND {$$ = createNode(AST_LOGICO_E, NULL);}
	| TK_OC_OR  {$$ = createNode(AST_LOGICO_OU, NULL);}
	| '<'       {$$ = createNode(AST_LOGICO_COMP_L, NULL);}
	| '>'       {$$ = createNode(AST_LOGICO_COMP_G, NULL);}
	| '!'		{$$ = createNode(AST_LOGICO_COMP_NEGACAO, NULL);}
	;
	
expressao 
	: literal tem_operador {$$ = createNode(AST_LITERAL, $1);} 
	| ID tem_operador
	| chamada_funcao tem_operador
	;

tem_operador
	: operador_aritmetico expressao
	| operador_aritmetico '(' expressao ')'
	| operador_logico expressao
	| operador_logico '(' expressao ')'
	| {$$ = NULL;}
	;







%%
