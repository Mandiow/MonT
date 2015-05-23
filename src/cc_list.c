
#include <stdio.h>
#include <stdlib.h>
#include "cc_list.h"

void initializeList(cc_list_t **list)
{
	*list = NULL;
	return;
}
//Ela é exclusiva para manipulação dos arrays multi-dimensionais (APPEND INVERTIDO POR CAUSA DO PARSER LOL)
void listAppendElem(cc_list_t **list, int newValue)
{
	cc_list_t* auxList;
	auxList = *list;
	cc_list_t* newListElem;
	
	//Aloca novo elemento
	newListElem = (cc_list_t*)malloc(sizeof(cc_list_t));
	newListElem->value = newValue;
	newListElem->nextElem = NULL;
	
	//Se a lista é nula, atualiza ponteiro da lista original
	if(*list == NULL)
	{
		*list = newListElem;
		return;
	}

	//Caso contrário, adiciona elemento no final da lista original
	newListElem->nextElem = *list;
	*list = newListElem;
}

cc_list_t* listRemoveLastElem(cc_list_t *list)
{
	if(list->nextElem == NULL)
	{
		free(list);
		list = NULL;
		return list;
	}
	cc_list_t* auxList;
	auxList = list;
	while(auxList->nextElem != NULL)
	{
		auxList = auxList->nextElem;
	}
	free(auxList);
	auxList = NULL;
	return list;
}

void deleteList(cc_list_t **list)
{
	cc_list_t* auxList;
	cc_list_t* next;
	auxList = *list;
	next = auxList;
	while (next != NULL)
	{
		
		next = auxList->nextElem;
		free(auxList);
		auxList = next;
	}
	*list = NULL;
}
void printList(cc_list_t* list)
{
	cc_list_t* auxList;
	auxList = list;
	while(auxList != NULL)
	{
		printf("elemento:%d\n",auxList->value );
		auxList = auxList->nextElem;
	}

}
void copyList(cc_list_t* listSource,cc_list_t **listDestination)
{
	cc_list_t* auxList;
	auxList = listSource;
	while(auxList != NULL)
	{
		listCopyAppendElem(listDestination,auxList->value);
		auxList = auxList->nextElem;
	}
}

void listCopyAppendElem(cc_list_t **list, int newValue)
{
	cc_list_t* auxList;
	auxList = *list;
	cc_list_t* newListElem;
	
	//Aloca novo elemento
	newListElem = (cc_list_t*)malloc(sizeof(cc_list_t));
	newListElem->value = newValue;
	newListElem->nextElem = NULL;
	
	//Se a lista é nula, atualiza ponteiro da lista original
	if(*list == NULL)
	{
		*list = newListElem;
		return;
	}
	while(auxList->nextElem != NULL)
	{
		auxList = auxList->nextElem;
	}

	//Caso contrário, adiciona elemento no final da lista original
	auxList->nextElem = newListElem;
	return;
}