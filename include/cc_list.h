#ifndef __CC_LIST_H
#define __CC_LIST_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"


typedef struct ListaId { 
	int identificador; 
	struct ListaId *prox; 
} ListaIdentificadores;


// operações com a lista de identificadores
ListaIdentificadores *CriaListaIdentificadores(ListaIdentificadores *listaId);
ListaIdentificadores *AdicionaListaIdentificadores(int valor, ListaIdentificadores *listaId);
ListaIdentificadores* RemoveElementoListaIdentificadoresInicio(ListaIdentificadores *listaId);
int RemoveElementoListaIdentificadoresConteudo(int valor, ListaIdentificadores *listaId);
ListaIdentificadores* destroiListaIdentificadores(ListaIdentificadores *listaId);
int buscaElementoListaIdentificadores(int valor,  ListaIdentificadores *listaId);

#endif