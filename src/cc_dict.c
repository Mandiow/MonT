#include "cc_dict.h"
#define HASHSIZE 100

/*
 * Arquivo com as funções que serão utilizadas para criação do dicionário que conterá 
 * todas as informaçoes necessárias para a implementação inicial do projeto: os tokens, as chaves e sua ultima linha de aparição. 
 * É utilizada uma tabela hash (melhor tempo de acesso).
 * @authors Gabriel Alves <g04lves@gmail.com>, Inatan Hertzog <inatan.hertzog@gmail.com> 
*/

// Cria um dicionário vazio
comp_dict_t *dict_create(int size) {
    comp_dict_t *hashtable = NULL;
    int i;

    if(size <= 0) return NULL;
    hashtable = malloc(sizeof(comp_dict_t));
    hashtable->table = malloc(sizeof(comp_dict_item_t * ) * size);
    for(i = 0; i < size; i++)
        hashtable->table[i] = NULL;
    hashtable->size = size;

    printf("Dicionario Criado\n");
    return hashtable;
}

// Função Hash: cria posição de chave sem precisar criar colisão dada uma entrada s, que é a palavra
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
      hashval = *s + 31 * hashval;

    return hashval % HASHSIZE;
}

// Função dict_read: retorna simbolo correspondente ao lexema dado
struct comp_dict *dict_read(comp_dict_t *hashtable, char *key)
{
    struct comp_dict *node;
    for (node = hashtable[hash(key)]; node != NULL; node = node->next)
        if (strcmp(key, node->key) == 0)
        {
          printf("NODE FOUND: %s", node->key);
          return node; /* found */
        }
    return NULL; /* not found */
}

// Função dict_insert: insere a key no dicionário, verificando se houve colisão de chaves e tratando da maneira necessária
struct comp_dict *dict_insert(comp_dict_t *hashtable, char *key, char *token, int line)
{
    comp_dict *node = dict_read(hashtable,key);

    unsigned hashval;
    hashval = hash(key);

    // Se o nodo não foi encontrado (na real se o primeiro elemento da posição na tabela hash é vazio), é só adicionar direto
    if (node == NULL) 
    {
        node = malloc(sizeof(comp_dict_item_t));
        node->line = line;
        node->token = strdup(token);
        node->next = NULL;
        hashtable->table[hashval] = node;
    }

    //Agora caso eu já tenha pelo menos um nodo alocado naquela posição da Hash (Colisão), verificar se a key já está na lista ou não
    else 
    {
        comp_dict_item_t *aux;
        int nodeFound = 0;
        while(node != NULL)
        {
            if (strcmp(key, node->key) == 0) // As keys são as mesmas
            {
                if(strcmp(token, node->token) != 0)  // Mas os tokens foram diferentes
                {
                    free(node->token);              // Libera o antigo e atualiza
                    node->token = strdup(token);
                    node->line = line;

                    nodeFound = 1;                  // Marca que o nodo foi encontrado e atualizado.
                }
            }
            aux = node;
            node = node->next; 
        }
        if(nodeFound = 0) //Como o nodo não foi encontrado, nenhum valor foi atualizado, logo ele tem que ser adicionado na lista
            { 
                node = malloc(sizeof(comp_dict_item_t));
                node->token = strdup(token);
                node->key = strdup(key);
                node->line = line;
                node->next = NULL;
                aux->next = node;
            }
    }
    return node;
}

// TODO: Funções de desalocar dicionários (destruir)... zzzzzzzz