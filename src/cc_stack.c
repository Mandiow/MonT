#include "../include/cc_stack.h"
#include "../include/cc_list.h"
#include <stdio.h>
#include <stdlib.h>

PilhaIdentificadores *CriaPilha(/*PilhaIdentificadores *pilha*/)
{
	/*pilha = malloc(sizeof(PilhaIdentificadores));
	pilha->conteudo = NULL;
	pilha->prox = NULL;*/
	return NULL;
}

// Coloca y na pilha tp. 
void Empilha(ListaIdentificadores *conteudo, PilhaIdentificadores **topo) 
{ 
	PilhaIdentificadores *nova; 
	nova = malloc(sizeof(PilhaIdentificadores)); 
	nova->conteudo = conteudo;
	nova->prox = *topo;
	*topo = nova;
} 

// Remove um elemento da pilha tp 
// e devolve o elemento removido. 
// Supõe que a pilha não está vazia. 
ListaIdentificadores* Desempilha( PilhaIdentificadores **topo) 
{ 
	ListaIdentificadores *conteudo; 
	PilhaIdentificadores *retirado; 
	if(*topo != NULL)
	{
		retirado = *topo; 
		conteudo = retirado->conteudo; 
		*topo = retirado->prox;
 		free(retirado);
 		return conteudo; 
 	}
 	else
 		return NULL;
}

void DestroiPilha(PilhaIdentificadores **topo)
{
	ListaIdentificadores *Li;
	while(*topo != NULL)
	{
		Li = Desempilha(topo);
		destroiListaIdentificadores(Li);
	}	
}

int buscaIdentificadorPilha(int valor, PilhaIdentificadores *PilhaId)
{
	PilhaIdentificadores *Pi, *Pireversa;
	ListaIdentificadores *PiTroca;
	int fim=-1;
	Pi= PilhaId;
	while(Pi != NULL)
	{
		if(fim == -1) // provisório!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			PiTroca = Desempilha(&Pi);
			Empilha(PiTroca, &Pireversa);
			fim = buscaElementoListaIdentificadores(valor,PiTroca);
		}
		else
		{
			while(Pireversa != NULL)
			{
				PiTroca = Desempilha(&Pireversa);
				Empilha(PiTroca, &Pi);
			}
			return 0;
		}
	}
	while(Pireversa != NULL)
	{
		PiTroca = Desempilha(&Pireversa);
		Empilha(PiTroca, &Pi);		
	}
	if(fim ==-1)	
		return -1;
	else
		return 0;
}



