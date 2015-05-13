#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_iloc.h"

/*
*Função createRegister: int , char* -> ILOC_register_t*
*Verifica se o registrador está escrito de maneira correta em ILOC e adiciona o dado no registrador
*Retorna um Registrador novo com o dado atualizado.
*/
ILOC_register_t* createRegister(int data, char *reg_name)
{
	ILOC_register_t* newRegister;
	if(reg_name[0] == 'r')
	{
		newRegister.data = data;
		newRegister->name = reg_name;
		return newRegister;
	}
	else
		return NULL;
}

/*
* Função createLabel char* , int -> ILOC_label_t*
* A função serve para verificar se a label já existe no programa e se ela possui as regras de label na linguagem.
* Retorna a label caso ela seja criada com sucesso e retorna NULL em caso de erro ou a label já exista.
*/
ILOC_label_t*  createLabel(char* label_name, int position)
{
	ILOC_label_t newLabel;
	if(label_name[0] == 'L' && label_name[(strlen(label_name)-1)] == ':') // verfica se o primeiro caractere é 'L' e se ao encontrar a label se o ultimo caractere é ':' para definição do label
	{
		newLabel.position = position;
		label_name[(strlen(label_name)-1)] = '\0';	
		newLabel->name= label_name;
		return newLabel;
	}
	else
		return NULL;
}
