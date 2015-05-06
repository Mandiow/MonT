/*
  Coloque aqui o identificador do grupo e dos seus membros
*/
%{
#include <stdio.h>
#include <math.h>
#include "main.h"
#include "cc_misc.h"
int Func_type;
int param = 0;
int chamada = 0;
%}
%union
{
	struct comp_tree_t *syntaxTree;
	struct stack_item *main_stack;
	struct stack_item *call_stack;
	struct comp_dict_item_t *valor_simbolo_lexico;
	int type;

}



/* Declaração dos tokens da linguagem */
%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_CHAR
%token TK_PR_STRING
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
%type<syntaxTree> escopo
%type<syntaxTree> declarar_funcao
%type<syntaxTree> declaracao_local
%type<syntaxTree> bloco_comando
%type<syntaxTree> comando
%type<syntaxTree> ID
%type<syntaxTree> nome
%type<syntaxTree> atribuicao
%type<syntaxTree> controle_fluxo
%type<syntaxTree> chamada_funcao
%type<syntaxTree> expressao
%type<syntaxTree> retorno
%type<syntaxTree> entrada
%type<syntaxTree> saida
%type<syntaxTree> lista_expressoes
%type<syntaxTree> lista_vazia
%type<syntaxTree> mais_de_uma
%type<syntaxTree> valor
%type<valor_simbolo_lexico> '='
%type<valor_simbolo_lexico> '{'
%type<valor_simbolo_lexico> '}'
%type<valor_simbolo_lexico> '!'
%type<syntaxTree> literal
%type<type> especificador_tipo

/*DISCLAIMER: A contra gosto usei os lefts para assegurar a AST, 
			  na formulação de expressão, usada anteriormente
			  a precedência de operadores só era mantida até 
			  multiplicações e divisões, não respeitando ().
			  Dado este fato, reescrevi e usei os lefts =.=
*/
%left TK_OC_OR
%left TK_OC_AND
%left '<' '>' TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE
%left '+' '-'
%left '*' '/'
%left TK_OC_NOT


%nonassoc LOWER_THAN_ELSE
%nonassoc TK_PR_ELSE
%%
/* Regras (e ações) da gramática */
/* $$ = start 
   $1 = programa
*/
start: programa {
					$$ = createNode(AST_PROGRAMA,NULL);
					if($1 != NULL)appendChildNode($$,$1);
					gv_create_initial_tree($$); 
					syntaxTree = $$;
					removeNode(syntaxTree);}
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
	: declaracao_global ';' programa {$$=$3;}
	| declarar_funcao programa {$$ = $1;if($2 != NULL)appendChildNode($$,$2);}
	| {$$ = NULL;} 
	;

declaracao_global
	: especificador_tipo TK_IDENTIFICADOR '[' Array ']' {$2->iks_type = $1;$2->nodeType = AST_VETOR_INDEXADO; stack_push(&main_stack,$2,data_item, 1);}
	| especificador_tipo TK_IDENTIFICADOR {$2->iks_type = $1;$2->nodeType = AST_IDENTIFICADOR; stack_push(&main_stack,$2,data_item, 1);}
	| TK_PR_STATIC especificador_tipo  TK_IDENTIFICADOR '[' Array ']' { $3->iks_type = $2;$3->nodeType = AST_VETOR_INDEXADO;stack_push(&main_stack,$3,data_item, 1);}
	;

Array
	: TK_LIT_INT ',' Array
	| TK_LIT_INT {if($1->token.integer > 0)$$ = $1;}
	;

declarar_funcao	
	: escopo '(' parametros_vazio ')'
									{paramcounter(&main_stack,param);}
									'{' 
								bloco_comando 
									'}' 
									{ $$ = $1;
										if($7 !=NULL)
											appendChildNode($$,$7);
										
										param = 0;
										stack_popBlock(&main_stack);
									}
	| TK_PR_STATIC especificador_tipo TK_IDENTIFICADOR '(' parametros_vazio ')' {Func_type = $2;} '{' bloco_comando '}' {$$ = createNode(AST_FUNCAO,$3);if($9 !=NULL)appendChildNode($$,$9);}
	;


escopo
	:especificador_tipo TK_IDENTIFICADOR {Func_type = $1;$2->iks_type = $1; $$ = createNode(AST_FUNCAO,$2);stack_push(&main_stack,$2,func_item, 1);}
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
	: especificador_tipo TK_IDENTIFICADOR {$2->iks_type = $1; stack_push(&main_stack,$2,param_item, 1); param++;}
	| TK_PR_CONST especificador_tipo TK_IDENTIFICADOR {$3->iks_type = $2;stack_push(&main_stack,$3,param_item, 1); param++;}
	;

literal
	: TK_LIT_INT {$$ = createNode(AST_LITERAL, $1); }
	| TK_LIT_FLOAT {$$ = createNode(AST_LITERAL, $1);}
	| TK_LIT_FALSE {$$ = createNode(AST_LITERAL, $1);}
	| TK_LIT_TRUE {$$ = createNode(AST_LITERAL, $1);}
	| TK_LIT_CHAR {$$ = createNode(AST_LITERAL, $1);}
	| TK_LIT_STRING {$$ = createNode(AST_LITERAL, $1);}
	;

especificador_tipo
	: TK_PR_INT  {$$ = IKS_INT;}
	| TK_PR_FLOAT {$$ = IKS_FLOAT;}
	| TK_PR_BOOL {$$ = IKS_BOOL;}
	| TK_PR_CHAR {$$ = IKS_CHAR;}
	| TK_PR_STRING {$$ = IKS_STRING;}
	;

declaracao_local
	: especificador_tipo TK_IDENTIFICADOR   {$$ = NULL;$2->nodeType = AST_IDENTIFICADOR; $2->iks_type = $1;stack_push(&main_stack,$2,data_item, 1);}
	| especificador_tipo TK_IDENTIFICADOR TK_OC_LE valor {$$ = NULL;}
	| TK_PR_STATIC especificador_tipo TK_IDENTIFICADOR {$$ = NULL;}
	| TK_PR_STATIC especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor {$$ = NULL;}
	| TK_PR_STATIC TK_PR_CONST especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor {$$ = NULL;}
	| TK_PR_CONST especificador_tipo  TK_IDENTIFICADOR TK_OC_LE valor {$$ = NULL;}
	;

valor
	: literal {$$ = $1;}
	| TK_IDENTIFICADOR {$$ = createNode(AST_IDENTIFICADOR,$1);}
	;

ID
	: TK_IDENTIFICADOR {stack_isDeclared(main_stack,$1,AST_IDENTIFICADOR);$$ = createNode(AST_IDENTIFICADOR,$1);}
	| TK_IDENTIFICADOR  '[' Exparray ']' {	$$ = createNode(AST_VETOR_INDEXADO,NULL);
											stack_isDeclared(main_stack,$1,AST_VETOR_INDEXADO);
											if ($3->tableItem->iks_type == IKS_STRING) exit(IKS_ERROR_STRING_TO_X);
											if ($3->tableItem->iks_type == IKS_CHAR) exit(IKS_ERROR_CHAR_TO_X);
											appendChildNode($$,createNode(AST_IDENTIFICADOR,$1));
											appendChildNode($$,$3);
											
										   }
	;

Exparray
	: expressao ',' Exparray
	| expressao {$$ = $1;}
	;

atribuicao 
	: ID '=' expressao {
							$$ = createNode(AST_ATRIBUICAO,$2); 
							appendChildNode($$,$1);
							appendChildNode($$,$3);
							typeInference($1,$3);}
	;

retorno
	: TK_PR_RETURN expressao {$$ = createNode(AST_RETURN,NULL); $$->tableItem->iks_type = Func_type;appendChildNode($$,$2);typeCoercion($$->tableItem,$2->tableItem,1);}
	| TK_PR_RETURN {$$ = createNode(AST_RETURN,NULL); }
	;

bloco_comando
	:  comando ';' bloco_comando {$$ = $1; if($1 != NULL)appendChildNode($$,$3);else $$ = $3;} 
	|  comando {if($1 != NULL)$$ = $1;}
	|  {$$ = NULL;}
	;

comando
	: retorno  				{$$ = $1;}
	| atribuicao 			{$$ = $1;}
	| declaracao_local  	{$$ = $1;}
    | controle_fluxo 		{$$ = $1;}
	| '{'{stack_push(&main_stack,$1,block_item, 0);} bloco_comando '}'{stack_popBlock(&main_stack);stack_pop(&main_stack); $$ = createNode(AST_BLOCO, NULL);appendChildNode($$,$3);} //CUIDAR MUITO BEM DISSO, COM CARINHO E COM AMOR;
	| entrada 				{$$ = $1;}
	| chamada_funcao		{$$ = $1;} 
	| saida 				{$$ = $1;}
	;

entrada
	: TK_PR_INPUT expressao '=''>' expressao {$$ = createNode(AST_INPUT, NULL); appendChildNode($$,$2);appendChildNode($$,$5);typeCoercion($2->tableItem,$5->tableItem,2);}
	;

saida
	: TK_PR_OUTPUT lista_expressoes	 {$$ = createNode(AST_OUTPUT,NULL);appendChildNode($$,$2);if($2->tableItem->iks_type == IKS_CHAR)exit(IKS_WRONG_PAR_OUTPUT);}
	;

lista_vazia
	: lista_expressoes {$$ = $1;}
	| {$$ = NULL;}
	;

lista_expressoes
	: expressao mais_de_uma {	$$ = $1; 
								stack_push(&call_stack, $1->tableItem,param_item, 0);
								if($2 != NULL)
								{
									appendChildNode($$,$2);
									stack_push(&call_stack, $2->tableItem,param_item, 0);
								}
							}
	;

mais_de_uma
	: ',' lista_expressoes {$$ = $2; chamada++;}
	| {$$ = NULL; chamada++;}
	;

controle_fluxo
	: TK_PR_IF '(' expressao ')'  TK_PR_THEN comando TK_PR_ELSE comando {$$ = createNode(AST_IF_ELSE,NULL); appendChildNode($$,$3);appendChildNode($$,$6);appendChildNode($$,$8);}
	| TK_PR_IF '(' expressao ')'  TK_PR_THEN comando %prec LOWER_THAN_ELSE {$$ = createNode(AST_IF_ELSE,NULL); appendChildNode($$,$3);appendChildNode($$,$6);}
	| TK_PR_WHILE '(' expressao ')' TK_PR_DO comando {$$ = createNode(AST_WHILE_DO,NULL); appendChildNode($$,$3);appendChildNode($$,$6);}
	| TK_PR_DO comando TK_PR_WHILE '(' expressao ')' {$$ = createNode(AST_DO_WHILE,NULL); appendChildNode($$,$2);appendChildNode($$,$5);}
	;

chamada_funcao
	: nome  '(' lista_vazia ')' {Function_Comparsion(chamada,main_stack,call_stack); $$ = createNode(AST_CHAMADA_DE_FUNCAO,NULL); appendChildNode($$,$1);if($3 != NULL) {appendChildNode($$,$3);}$$->tableItem->iks_type = getFunctionType(main_stack,call_stack); chamada = 0;}
	;

nome: TK_IDENTIFICADOR {stack_isDeclared(main_stack,$1,AST_FUNCAO);$$ = createNode(AST_IDENTIFICADOR,$1);stack_push(&call_stack,$1,func_item, 0);}
	;

expressao 
	: ID 									{$$ = $1;}
	| literal 								{$$ = $1;}
	| expressao '/' expressao				{$$ = createNode(AST_ARIM_DIVISAO, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao '*' expressao				{$$ = createNode(AST_ARIM_MULTIPLICACAO, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao '-' expressao				{$$ = createNode(AST_ARIM_SUBTRACAO, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao '+' expressao				{$$ = createNode(AST_ARIM_SOMA, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| '-' expressao							{$$ = createNode(AST_ARIM_INVERSAO, NULL);appendChildNode($$,$2);}
	| TK_OC_NOT expressao					{$$ = createNode(AST_LOGICO_COMP_NEGACAO, NULL);appendChildNode($$,$2);}
	| expressao '<' expressao				{$$ = createNode(AST_LOGICO_COMP_L, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao '>' expressao				{$$ = createNode(AST_LOGICO_COMP_G, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_LE expressao			{$$ = createNode(AST_LOGICO_COMP_LE, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_GE expressao			{$$ = createNode(AST_LOGICO_COMP_GE, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_EQ expressao			{$$ = createNode(AST_LOGICO_COMP_IGUAL, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_NE expressao			{$$ = createNode(AST_LOGICO_COMP_DIF, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_AND expressao			{$$ = createNode(AST_LOGICO_E, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| expressao TK_OC_OR expressao			{$$ = createNode(AST_LOGICO_OU, NULL);appendChildNode($$,$1);appendChildNode($$,$3);typeInference($1,$3);}
	| '(' expressao ')'						{$$ = $2;}
	| chamada_funcao 						{$$ = $1;}
	;

%%
