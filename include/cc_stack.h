#ifndef __CC_STACK_H
#define __CC_STACK_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"




typedef struct ListaId { 
	int identificador; 
	struct Lista *prox; 
} ListaIdentificadores;

typedef struct cel { 
	ListaIdentificadores conteudo; 
	struct cel *prox; 
} PilhaIdentificadores;



void CriaPilha(PilhaIdentificadores *pilha);
void Empilha(int y, celula *tp);
int Desempilha(PilhaIdentificadores *tp);
void DestroiPilha(cedula *pilha);


// operações com a lista de identificadores
void CriaListaIdentificadores(ListaIdentificadores *listaId);
void AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId);
void destroiListaIdentificadores(ListaIdentificadores *listaId);
int buscaElementoListaIdentificadores(int valor,  ListaIdentificadores *listaId);

#endif


