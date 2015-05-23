#include "cc_strack.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(PilhaIdentificadores *pilha)
{
	pilha = NULL;
}

// Coloca y na pilha tp. 
void Empilha( ListaIdentificadores *y, PilhaIdentificadores *tp) 
{ 
	PilhaIdentificadores *nova; 
	nova = mallocc(sizeof (celula)); 
	nova->conteudo = y;
	nova->prox = tp->prox; 
	tp->prox = nova; 
} 

// Remove um elemento da pilha tp 
// e devolve o elemento removido. 
// Supõe que a pilha não está vazia. 
int Desempilha( PilhaIdentificadores *tp) 
{ 
	ListaIdentificadores *x; 
	PilhaIdentificadores *p; 
	if(tp != NULL)
	{
		p = tp->prox; 
		x = p->conteudo; 
		tp->prox = p->prox;
 		free(p); 
 		return x; 
 	}
 	else
 		return NULL;
}

void DestroiPilha(PilhaIdentificadores *pilha)
{
	ListaIdentificadores *Li;
	while(pilha != NULL)
	{
		Li = desempilha(pilha);
	}	
}

void CriaListaIdentificadores(ListaIdentificadores *listaId)
{
	listaId = NULL;
}


void AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId)
{
   ListaIdentificadores *nova;
   nova = mallocc( sizeof (ListaIdentificadores));
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

int buscaIdentificadorPilha(int valor, PilhaIdentificadores *PilhaId)
{
	PilhaIdentificadores *Pi, *Pireversa;
	ListaIdentificadores *PiTroca;
	int fim=0;
	Pireversa= NULL;
	PiTroca = NULL;
	Pi= PilhaId;
	
	while(Pi->prox != NULL)
	{
		if(fim < 0)
		{
			PiTroca = Desempilha(Pi);
			Empilha(Pitroca, Pireversa);
			fim = buscaElementoListaIdentificadores(valor,Pitroca);
		}
		else
		{
			while(Pireversa != NULL)
			{
				PiTroca = Desempilha(Pireversa);
				Empilha(Pitroca, Pi);
			}
			return 0;
		}
	}
	while(Pireversa != NULL)
	{
		PiTroca = Desempilha(Pireversa);
		Empilha(Pitroca, Pi);		
	}	
	return -1;
}



