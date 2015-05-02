#include "cc_misc.h"
#include "cc_dict.h"
#include "cc_stack.h"

extern lineNumber;

int getLineNumber (void)
{
  return lineNumber;
}

void yyerror (char const *mensagem)
{
  fprintf (stderr, "%s\n linha: %d\n", mensagem, getLineNumber()); //altere para que apareça a linha
}

void main_init (int argc, char **argv)
{
  //implemente esta função com rotinas de inicialização, se necessário
	dict_create(100);
	//stack_initialize(main_stack);
}

void main_finalize (void)
{
  //implemente esta função com rotinas de inicialização, se necessário
  dict_release(hashtable);
}
