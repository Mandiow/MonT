#ifndef __CC_STACK_H
#define __CC_STACK_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"
#include "cc_list.h"


typedef struct cel { 
	ListaIdentificadores *conteudo;
	struct cel *prox; 
} PilhaIdentificadores;



PilhaIdentificadores *CriaPilha(/*PilhaIdentificadores *pilha*/);
void Empilha(ListaIdentificadores* conteudo, PilhaIdentificadores **topo);
ListaIdentificadores* Desempilha(PilhaIdentificadores **topo);
void DestroiPilha(PilhaIdentificadores **topo);
int buscaIdentificadorPilha(int valor, PilhaIdentificadores *PilhaId);
#endif


