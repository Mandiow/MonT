#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIMBOLO_LITERAL_INT    1
#define SIMBOLO_LITERAL_FLOAT  2
#define SIMBOLO_LITERAL_CHAR   3
#define SIMBOLO_LITERAL_STRING 4
#define SIMBOLO_LITERAL_BOOL   5
#define SIMBOLO_IDENTIFICADOR  6


union magic_token{
		int 	integer;
		float	floating_point;
		char 	single_char;
		char 	*string;
		int 	boolean;

	}magic_token; // DEPOIS EU MUDO =.=


struct comp_dict_item_t{  // item tabela de simbolos
    int line; // ultima linha de aparição do lexema
    int tipo;																		//char *token; // token do lexema  // ETAPA 2 Isso tem que vazar pro union aparecer
    union magic_token token;
    struct comp_dict_item_t *next; /* prox item da tabela de simbols */
    char *key; /* chave  para consultar o simbolo o lexical*/
};

struct comp_dict_t { /* tabela de simbolos */
    struct comp_dict_item_t **table; /* valor do item dessa chave */
    int size;
};


struct comp_dict_t* hashtable;	
