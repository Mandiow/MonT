#ifndef __CC_LIST_H
#define __CC_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "cc_list.h"

void initializeList(cc_list_t *list)
{
	list = NULL;
	return;
}

void listAppendElem(cc_list_t* list, int newValue)
{
	cc_list_t* auxList;
	auxList = list;
	if(list != NULL)
	{
		while(auxList->nextElem != NULL)
		{
			auxList = auxList->nextElem;
		}
		cc_list_t* newListElem;
		newListElem = (cc_list_t*)malloc(sizeof(cc_list_t));
		newListElem->nextElem = NULL;
		newListElem->value = newValue;
		auxList->nextElem = newListElem;	
	}
	else
	{
		cc_list_t* newListElem;
		newListElem = (cc_list_t*)malloc(sizeof(cc_list_t));
		newListElem->nextElem = NULL;
		newListElem->value = newValue;
		list = newListElem;
	}
}

void listRemoveLastElem(cc_list_t* list)
{
	if(list == NULL)
		return;
	cc_list_t* auxList;
	auxList = list;
	while(auxList->nextElem != NULL)
	{
		auxList = auxList->nextElem;
	}
	free(auxList->nextElem);
	auxList->nextElem = NULL;
}

void deleteList(cc_list_t* list)
{
	cc_list_t* auxList;
	auxList = list;
	while (auxList != NULL)
	{
		listRemoveLastElem(auxList);	
	}
}
#endif