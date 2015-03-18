/*
  Coloque aqui o identificador do grupo e dos seus membros


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

*/


%x comment

%{
#include "parser.h" //arquivo automaticamente gerado pelo bison
#include "main.c"
#include "cc_misc.c"




int lineNumber = 1;
%}

LIT_INT 		[0-9]+
LIT_FLOAT 		[0-9]+("."[0-9]+)?([eE][+-]?[0-9]+)?
LIT_CHAR 		\'.\'
LIT_STRING    \"(\\.|[^\\"])*\"
ID 					[A-Za-z_][A-Za-z_0-9]*
SPECIAL 		[,;:(){}\[\]{}\+\-\*<>=!&$\/]

%%
int 				 return TK_PR_INT;
float 				 return TK_PR_FLOAT;
bool 				 return TK_PR_BOOL;
char 				 return TK_PR_CHAR; 
string 				 return TK_PR_STRING; 
if 					 return TK_PR_IF; 
then 				 return TK_PR_THEN;
else 				 return TK_PR_ELSE; 
while 				 return TK_PR_WHILE; 
do 					 return TK_PR_DO; 
input 				 return TK_PR_INPUT; 
output 				 return TK_PR_OUTPUT; 
return 				 return TK_PR_RETURN;
const 				 return TK_PR_CONST;
static				 return TK_PR_STATIC;


  

"<=" 				       return TK_OC_LE;
">="				       return TK_OC_GE;
"==" 				       return TK_OC_EQ; 
"!=" 				       return TK_OC_NE; 
"&&" 				       return TK_OC_AND;
"||" 				       return TK_OC_OR;
"\n"				       getLineNumber();
"SPECIAL"          return yytext[0];
"/*" 				       BEGIN(comment);
<comment>"*/" 		 BEGIN(INITIAL);

.					 return TOKEN_ERRO;
%%
