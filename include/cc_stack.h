#ifndef __CC_STACK_H
#define __CC_STACK_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"



typedef struct cel { 
	int conteudo; 
	struct cel *prox; 
} PilhaIdentificadores;

typedef struct ListaId { 
	int identificador; 
	struct Lista *prox; 
} ListaIdentificadores;




void CriaPilha(PilhaIdentificadores *pilha);
void empilha(int y, celula *tp);
int desempilha(PilhaIdentificadores *tp);
void destroi(cedula *pilha);


// operações com a lista de identificadores
void CriaListaIdentificadores(ListaIdentificadores *listaId);
void AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId);
void destroiListaIdentificadores(ListaIdentificadores *listaId);


#endif


