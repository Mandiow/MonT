#include "cc_misc.h"

FILE *fOutput;
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
	if(argc != 2)
	{
		fOutput = fopen(argv[2], "w");
	}
	dict_create(100);
	//stack_initialize(main_stack);
}

void main_finalize (void)
{
  //implemente esta função com rotinas de inicialização, se necessário
	char ilocCodeOutput[2048];
	strcpy(ilocCodeOutput,"");
  	
  	if(!fOutput)
  	{
  		printf("Erro no arquivo de saída, Terminando...\n");
  		abort();
  	}
  		fprintf(fOutput, "%s\n", astCodeGenerate(syntaxTree));
  	removeNode(syntaxTree);
  	dict_release(hashtable);
}