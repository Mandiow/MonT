#ifndef __CC_LIST_H
#define __CC_LIST_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"
#include "cc_stack.h"


typedef struct ListaId { 
	int identificador; 
	struct Lista *prox; 
} ListaIdentificadores;


// operações com a lista de identificadores
void CriaListaIdentificadores(ListaIdentificadores *listaId);
void AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId);
void RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId);
void destroiListaIdentificadores(ListaIdentificadores *listaId);
int buscaElementoListaIdentificadores(int valor,  ListaIdentificadores *listaId);

#endif