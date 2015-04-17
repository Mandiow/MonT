#include "cc_dict.h"


/*
 * Arquivo com as funções que serão utilizadas para criação do dicionário que conterá 
 * todas as informaçoes necessárias para a implementação inicial do projeto: os tokens, as chaves e sua ultima linha de aparição. 
 * É utilizada uma tabela hash (melhor tempo de acesso).
 * @authors Gabriel Alves <g04lves@gmail.com>, Inatan Hertzog <inatan.hertzog@gmail.com>
 * @debugged Caiã de Aragão Frazão <cafrazao@inf.ufrgs.br>



 100% nos testes, não sei se é a coisa mais esperta que eu já fiz, corrigido... eu acho ;3 - Caiã
*/

// Cria um dicionário vazio

struct comp_dict_t *dict_create(int size) {
    int i;
    if(size <= 0) return NULL;
    hashtable = malloc(sizeof(struct comp_dict_t));
    hashtable->table = malloc(sizeof(struct comp_dict_item_t * ) * size);
    for(i = 0; i < size; i++)
        hashtable->table[i] = NULL;
    hashtable->size = size;

    return hashtable;
}



// Função Hash: cria posição de chave sem precisar criar colisão dada uma entrada s, que é a palavra
unsigned hash(char *s, int hashsize)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;

    return hashval % hashsize;
}

// Função dict_read: retorna simbolo correspondente ao lexema dado
struct comp_dict_item_t *dict_read(struct comp_dict_t *hashtable, char *key)
{
    struct comp_dict_item_t *search = NULL;

    if(hashtable->table[hash(key, hashtable->size)] != NULL) 
    {
            /*(for(; search != NULL; search = search->next) 
               if(search->key != NULL)
                  if(strcmp(key, search->key) == 0)
                    {
                    Então, essa verificação já existe lá em baixo, o comflito gerava um espaço bizarro na memória
                    }*/
            search = hashtable->table[hash(key, hashtable->size)];
            return search;
        
    }
    return NULL;
}

// Função dict_insert: insere a key no dicionário, verificando se houve colisão de chaves e tratando da maneira necessária
struct comp_dict_item_t *dict_insert(struct comp_dict_t *hashtable, char *key, int TK_some_symbol_comes, int line)
{
    
   
    unsigned hashval;
    hashval = hash(key, hashtable->size);
    struct comp_dict_item_t *node = dict_read(hashtable,key);
    // Se o nodo não foi encontrado (na real se o primeiro elemento da posição na tabela hash é vazio), é só adicionar direto
    if (node == NULL) 
    {
        node = malloc(sizeof(struct comp_dict_item_t));
        //node->token.string = strdup(key);
        node->line = line;
        node->key = strdup(key);
                    switch(TK_some_symbol_comes) 
                    {
                        case SIMBOLO_LITERAL_INT:
                            node->token.integer = atoi(key);
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_FLOAT:
                            node->token.floating_point = atof(key);
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_CHAR:
                            node->token.single_char = key[1];
                            node->key = strtok(key,"\'");
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_STRING:
                            node->token.string = strtok(key,"\"");
                            node->key = strtok(key,"\"");
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_BOOL:
                            node->tipo = TK_some_symbol_comes;
                            if(strcmp(key,"true"))
                                node->token.boolean = 1; //Caso Token Boolean = True

                            else    
                                node->token.boolean = 0; //Caso Token Boolean = False
                            break;
                        case SIMBOLO_IDENTIFICADOR:
                            node->tipo = TK_some_symbol_comes;
                            node->token.string = strtok(key,"\"");
                            break;

                        }
        node->next = NULL;

        hashtable->table[hashval] = node;

    }
    //Agora caso eu já tenha pelo menos um nodo alocado naquela posição da Hash (Colisão), verificar se a key já está na lista ou não
    else 
    {
        struct comp_dict_item_t *aux;
        int nodeFound = 0;
        while(node != NULL)
        {
            if (strcmp(key, node->key) == 0) // As keys são as mesmas
            {
                    node->line = line;
                    nodeFound = 1;                  // Marca que o nodo foi encontrado e atualizado.
                
            }
            aux = node;
            node = node->next; 
        }
        if(nodeFound == 0) //Como o nodo não foi encontrado, nenhum valor foi atualizado, logo ele tem que ser adicionado na lista
            { 
                node = malloc(sizeof(struct comp_dict_item_t));
                node->key = strdup(key);
                switch(TK_some_symbol_comes) 
                    {
                        case SIMBOLO_LITERAL_INT:
                            node->token.integer = atoi(key);
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_FLOAT:
                            node->token.floating_point = atof(key);
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_CHAR:
                            node->token.single_char = key[1];
                            node->key = strtok(key,"\'");
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_STRING:
                            node->token.string = strtok(key,"\"");
                            node->key = strtok(key,"\"");
                            node->tipo = TK_some_symbol_comes;
                            break;
                        case SIMBOLO_LITERAL_BOOL:
                            node->tipo = TK_some_symbol_comes;
                            if(strcmp(key,"true"))
                                node->token.boolean = 1; //Caso Token Boolean = True

                            else    
                                node->token.boolean = 0; //Caso Token Boolean = False
                            break;
                        case SIMBOLO_IDENTIFICADOR:
                            node->tipo = TK_some_symbol_comes;
                            node->token.string = strtok(key,"\"");
                            break;
                        }
                node->line = line;
                node->next = NULL;
                aux->next = node;
               
            }
    }
    return node;
}

// Desaloca e libera a memória utilizada pelo dicionário
// Entrada: dicionário a ser destruído
void dict_release (struct comp_dict_t* hashtable) 
{
    struct comp_dict_item_t *aux_item;
    struct comp_dict_item_t *next_item;
    int i;
    for(i=0;i<hashtable->size;i++)
    {
        aux_item = hashtable->table[i];
        while (aux_item != NULL) 
        {
            next_item = aux_item->next;
            if(aux_item->tipo != SIMBOLO_LITERAL_STRING && aux_item->tipo != SIMBOLO_LITERAL_CHAR) free(aux_item->key);
            free(aux_item);
            aux_item = next_item;
        }
    }
    free(hashtable->table);
    free(hashtable);
}
