#include "cc_list.h"
#include <stdio.h>
#include <stdlib.h>



void CriaListaIdentificadores(ListaIdentificadores *listaId)
{
	listaId = mallocc(sizeof (ListaIdentificadores));
	listaId->prox = NULL;
}


void AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId)
{
   ListaIdentificadores *nova;
   nova = mallocc(sizeof (ListaIdentificadores));
   nova->conteudo = valor;
   nova->prox= NULL;
   while( listaId->prox != NULL)
   {
   		listaId=listaId->prox;
   }
   p->prox = nova;
}

void RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId)
{
  ListaIdentificadores *morto;
  if (listaId!=NULL)
  {
   	morto = listaId;
    listaId = listaId->prox;
    free(morto);
  }
}

void RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId)
{	
	ListaIdentificadores *morto;
	ListaIdentificadores *antes;
	morto = listaId;
   	while (morto !=NULL)
    {
	 	if (morto->identificador == dado) // achou !!
	 	{
	   		if (morto == listaId) // se esta removendo o primeiro da lista
	   		{
     			listaId = listaId->prox;
       			free(morto);
       			return 1; // removeu !!
    		}
    		else  // esta removendo do meio da lista
    		{
      			antes->prox = morto->prox;  // Refaz o encadeamento
      			free(morto);                // Libera a area do nodo
    			return 1;   // removeu !!
    		}
 		}
 		else  // continua procurando no prox. nodo
 		{
    		antes = morto;
    		morto = morto->prox;
 		}
   }
}

void destroiListaIdentificadores(ListaIdentificadores *listaId)
{
	while(listId != NULL)
	{
		RemoveElementoListaIdentificadoresInicio(listId);
	}
}

int buscaElementoListaIdentificadores(int valor,  ListaIdentificadores *listaId)
{
	ListaIdentificadores *Li;
	Li = listaId;
	while(Li->prox != NULL)
	{
		if(Li->identificador == valor)
			return valor;
		Li=Li->prox;
	}
	return -1;
}
