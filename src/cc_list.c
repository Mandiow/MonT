#include "../include/cc_list.h"
#include <stdio.h>
#include <stdlib.h>



ListaIdentificadores *CriaListaIdentificadores(ListaIdentificadores *listaId)
{
	listaId = malloc(sizeof (ListaIdentificadores));
	/*listaId->prox = NULL;
	return listaId;*/
	return NULL;
}


ListaIdentificadores *AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId)
{
  ListaIdentificadores* novoElemento;
  novoElemento = malloc(sizeof(ListaIdentificadores));
  novoElemento->identificador = valor;
  if(listaId==NULL)
  	return novoElemento;
  ListaIdentificadores* listaAux;
  listaAux = listaId;

  while(listaAux->prox != NULL)
  {
    listaAux = listaAux->prox;
  }
  listaAux->prox = novoElemento;
  return listaId;
}

ListaIdentificadores* RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId)
{
  ListaIdentificadores *morto,*listaIdAux;
  listaIdAux= listaId;
  if (listaIdAux!=NULL)
  {
   	morto = listaIdAux;
    listaIdAux = listaIdAux->prox;
    free(morto);
  }
  return listaIdAux;
}

int RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId)
{	
	ListaIdentificadores *morto;
	ListaIdentificadores *antes;
	morto = listaId;
   	while (morto !=NULL)
    {
	 	if (morto->identificador == valor) // achou !!
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

ListaIdentificadores* destroiListaIdentificadores(ListaIdentificadores *listaId)
{
	while(listaId != NULL)
	{
		RemoveElementoListaIdentificadoresInicio(listaId);
		listaId= listaId->prox;
	}
	return listaId;
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
