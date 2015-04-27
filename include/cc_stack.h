#ifndef __CC_STACK_H
#define __CC_STACK_H
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"

typedef struct cel { 
	int conteudo; 
	struct cel *prox; 
} celula;



void inicia(cedula *pilha);
void empilha(int y, celula *tp);
int desempilha(celula *tp);
void destroi(cedula *pilha);

#endif


