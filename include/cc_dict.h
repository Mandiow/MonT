#ifndef __CC_DICT_H
#define __CC_DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_list.h"
#define SIMBOLO_LITERAL_INT    1
#define SIMBOLO_LITERAL_FLOAT  2
#define SIMBOLO_LITERAL_CHAR   3
#define SIMBOLO_LITERAL_STRING 4
#define SIMBOLO_LITERAL_BOOL   5
#define SIMBOLO_IDENTIFICADOR  6
#define IKS_INT                1
#define IKS_FLOAT              2
#define IKS_CHAR               3
#define IKS_STRING             4
#define IKS_BOOL               5

union magic_token{
		int 	integer;
		float	floating_point;
		char 	single_char;
		char 	*string;
		int 	boolean;

	}magic_token; // DEPOIS EU MUDO =.=

enum declarationType { localDeclaration = 0 , globalDeclaration = 1};

typedef struct comp_dict_item_t{  // item tabela de simbolos
    int line; // ultima linha de aparição do lexema
    int tipo;																		//char *token; // token do lexema  // ETAPA 2 Isso tem que vazar pro union aparecer
    int iks_type;                           // Type of the correspondent literal
    int coercion;                       // If coercion is used, exactly as it is defined in this file.
    int size;                           // As defined in this file.
    int offset;
    int param;
    int nodeType;
    int scopeType;                      // If the variable does have a local scope or if it is global (0 == Global, 1 == Have Local Scope) 
    cc_list_t* array;
    union magic_token token;
    char *functionLabel;            // Usado na chamada de função da etapa 6;
    struct comp_dict_item_t *next; /* prox item da tabela de simbols */
    char *key; /* chave  para consultar o simbolo o lexical*/
}comp_dict_item_t;

struct comp_dict_t { /* tabela de simbolos */
    struct comp_dict_item_t **table; /* valor do item dessa chave */
    int size;
};


struct comp_dict_t* hashtable;	




struct comp_dict_item_t *dict_read(struct comp_dict_t *hashtable, char *key);
unsigned hash(char *s, int hashsize);
char* cpy_str(char* line);

#endif