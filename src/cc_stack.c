#include "cc_strack.h"
#include <stdio.h>
#include <stdlib.h>

void CriaPilha(PilhaIdentificadores *pilha)
{
	
	pilha = mallocc(sizeof (PilhaIdentificadores));
	pilha->conteudo = NULL;
	pilha->pai = NULL;
	pilha->prox = NULL;
}

// Coloca y na pilha tp. 
void Empilha( ListaIdentificadores *conteudo, PilhaIdentificadores *pilha) 
{ 
	PilhaIdentificadores *nova; 
	nova = mallocc(sizeof (PilhaIdentificadores)); 
	nova->conteudo = conteudo;
	nova->prox = NULL;
	pilha->prox = nova; 
} 

// Remove um elemento da pilha tp 
// e devolve o elemento removido. 
// Supõe que a pilha não está vazia. 
ListaIdentificadores* Desempilha( PilhaIdentificadores *pilha) 
{ 
	ListaIdentificadores *conteudo; 
	PilhaIdentificadores *retirado; 
	if(pilha != NULL)
	{
		retirado = pilha; 
		conteudo = retirado->conteudo; 
		pilha = retirado->prox;
 		free(retirado);
 		return conteudo; 
 	}
 	else
 		return NULL;
}

void DestroiPilha(PilhaIdentificadores *pilha)
{
	ListaIdentificadores *Li;
	while(pilha != NULL)
	{
		Li = Desempilha(pilha);
		destroiListaIdentificadores(Li);
	}	
}


int buscaIdentificadorPilha(int valor, PilhaIdentificadores *PilhaId)
{
	PilhaIdentificadores *Pi, *Pireversa;
	ListaIdentificadores *PiTroca;
	int fim=-1;
	Pi= PilhaId;
	
	while(Pi->prox != NULL)
	{
		if(fim == -1) // provisório!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	return IKS_ERROR_UNDECLARED;
}



