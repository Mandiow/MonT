#include "cc_strack.h"
#include <stdio.h>
#include <stdlib.h>

void inicia(cedula *pilha)
{
	pilha = NULL;
}

// Coloca y na pilha tp. 
void empilha( int y, celula *tp) 
{ 
	celula *nova; 
	nova = mallocc(sizeof (celula)); 
	nova->conteudo = y;
	nova->prox = tp->prox; 
	tp->prox = nova; 
} 

// Remove um elemento da pilha tp 
// e devolve o elemento removido. 
// Supõe que a pilha não está vazia. 
int desempilha( celula *tp) 
{ 
	int x; 
	celula *p; 
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

void destroi(cedula *pilha)
{
	int elemento;
	while(pilha != NULL)
	{
		elemento = desempilha(pilha);
	}	
}


