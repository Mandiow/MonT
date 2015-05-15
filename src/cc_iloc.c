#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_iloc.h"

/*
*Função createRegister: void -> ILOC_register_t
*Cria uma registrador novo baseado nas regra de ILOC
*Retorna um novo Registrador 
*/
ILOC_register_t createRegister()
{
	ILOC_register_t newRegister;
	char *prefix,*sufix;
	prefix = 'r';
	sprintf(sufix, "%d", registerControl); 
	registerControl++;
	newRegister= strcat(prefix,sufix);
	return newRegister;

}

/*
* Função createLabel entrada: void -> ILOC_label_t:
* A função serve para criar uma label de acordo com as regras da linguagem iloc
* Retorna uma label nova
*/
ILOC_label_t createLabel()
{
	ILOC_label_t newLabel;
	char* prefix,*sufix;
	prefix = 'L';
	sprintf(sufix, "%d", labelControl); 
	labelControl++;
	newLabel= strcat(prefix,sufix);
	return newLabel;
}
