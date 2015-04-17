/*
  Caiã de Aragão
  Gabriel Alves
  Inatan Hertzog


  Antes das pedradas, entendam que meu git não coloca repositórios em private, então não tive como fazer isso, por isso estou fazendo aqui O-KA? ;3

  Enquanto a gente não coloca, vou explicar um pouco do que eu fiz por enquanto, ou pelo menos acho que consegui fazer.

  Defini Expressões regulares que formam inteiros, floats, char, string e caracteres especiais, bem como os tokens de palavras reservadas MENOS dos literais!!! Ainda tem que fazer isso e eu não faço idéia
  de como =.=

  Mesma coisa com os operandos, deixei eles já definidos, acho que não tem mais o que fazer com eles!
  %x comment é uma condição de inicio, ou pelo menos foi o que eu entendi do site mto bem documentado do http://flex.sourceforge.net/manual/. BEGIN(comment) é exatamente o inicio de condição e BEGIN(INITIAL) sai
  pelo que eu entendi ao menos

  A ÚLTIMA REGRA DE TOKEN DE ERRO DEVE SER A ÚLTIMA REGRA!!!!! O que eu entendi é que, quando ele passa por tudo, qualquer outra coisa(aqui, sinalizada por "." devolve um token de erro!)


  A função de contar linhas eu não vi mais nada de mto sábio pra se fazer além de simplesmente tacar um ++ dentro dela ok?, "\n" chama a função e eras isso, acho que tem como definir variáveis aqui nesse .l
  então o fiz, tá alí em baixo
  
  Eu tenho CERTEZA que tem algumas coisas bem importante faltando, segunda a gente conversa melhor!

  ESPERO QUE LEIAM SEUS LIMDOS ;3 


  Tentei identar o máximo que consegui, só que o arquivo sisma em não colaborar comigo =.= desisti e vai ficar assim mesmo ok gente? ¬_¬

*/


%x comment

%{
		#include "parser.h" //arquivo automaticamente gerado pelo bison
		#include "main.h"
		int lineNumber = 1;
		
		
		

%}

LIT_INT 		[0-9]+
LIT_FLOAT 		[0-9]+("."[0-9]+)?([eE][+-]?[0-9]+)?
LIT_CHAR 		\'.\'
LIT_STRING    \"(\\.|[^\\"])*\"
ID 					[A-Za-z_][A-Za-z_0-9]*
		

%%

int 				 {return TK_PR_INT;}
float 				 {return TK_PR_FLOAT;}
bool 				 {return TK_PR_BOOL;}
char 				 {return TK_PR_CHAR; }
string 				 {return TK_PR_STRING;} 
if 					 {return TK_PR_IF; }
then 				 {return TK_PR_THEN;}
else 				 {return TK_PR_ELSE; }
while 				 {return TK_PR_WHILE;} 
do 					 {return TK_PR_DO; }
input 				 {return TK_PR_INPUT; }
output 				 {return TK_PR_OUTPUT; }
return 				 {return TK_PR_RETURN;}
const 				 {return TK_PR_CONST;}
static				 {return TK_PR_STATIC;}


  
" "               {}
"\t"              {}
"\f"              {}
"\v"              {}
"<=" 				       {return TK_OC_LE;}
">="				       {return TK_OC_GE;}
"==" 				       {return TK_OC_EQ; }
"!=" 				       {return TK_OC_NE; }
"&&" 				       {return TK_OC_AND;}
"||" 				       {return TK_OC_OR;}
"\n"				       {++lineNumber;}
"!"               {return TK_OC_NOT;}

[,;:(){}\[\]{}\+\-\*<>=!&$\/]          		   {return yytext[0];}
"/*" 				       {BEGIN(comment);}
<comment>.          { }
<comment>"\n"       {lineNumber++;}
<comment>"*/"          {BEGIN(INITIAL);}

"//".*					   {}
{LIT_INT}				   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_LITERAL_INT,lineNumber); return TK_LIT_INT;}
{LIT_FLOAT}				   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_LITERAL_FLOAT,lineNumber); return TK_LIT_FLOAT;}
{LIT_CHAR}				   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_LITERAL_CHAR,lineNumber); return TK_LIT_CHAR;}
{LIT_STRING}			   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext, SIMBOLO_LITERAL_STRING,lineNumber); return TK_LIT_STRING;}
false					   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_LITERAL_BOOL,lineNumber); return TK_LIT_FALSE;}
true					   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_LITERAL_BOOL,lineNumber); return TK_LIT_TRUE;}
{ID}					   {yylval.valor_simbolo_lexico = dict_insert(hashtable,yytext,SIMBOLO_IDENTIFICADOR,lineNumber); return TK_IDENTIFICADOR;}


.					 	   {return TOKEN_ERRO;}
%destructor    {free(yylval.valor_simbolo_lexico);}
%%
