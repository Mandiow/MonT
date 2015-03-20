#include <stdio.h>
#include <stdlib.h>

struct comp_dict_item_t{  // item tabela de simbolos
    int line; // ultima linha de aparição do lexema
    char *token; // token do lexema
    struct comp_dict_item_t *next; /* prox item da tabela de simbols */
    char *key; /* chave  para consultar o simbolo o lexical*/
};

struct comp_dict { /* tabela de simbolos */
    struct **comp_dict_item_t table; /* valor do item dessa chave */
};
