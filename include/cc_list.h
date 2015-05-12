#ifndef __CC_LIST_H__
#define __CC_LIST_H__

#include "cc_iloc.h"
/*
* ILOC_operand
* um operando pode ser um literal, um registrado ou um valor da memória
* esse operando é usado para as operações da linguagem ILOC
*/
union ILOC_operand {
	int val;
	ILOC_register_t reg;
	ILOC_memory_cell_t mem;
}

/*
* ILOC_operand_list_t
* uma lista da operandos para a realização das instruções da linguagem ILOC
*/
typedef struct ILOC_operand_list{
	ILOC_operand op;
	struct ILOC_operand_list *prox;
}ILOC_operand_list_t;

/*
* ILOC_operand_target
* Operando o qual vão receber resultados das instruções só podem ser valores de memória e registradores
*/
union ILOC_operand_target{
	ILOC_register_t reg;
	ILOC_memory_cell_t mem;
}

/*
* ILOC_instruction_t
* Uma instrução possui uma operação, uma lista de operandos fontes e um operando alvo para o resultado da operação
*/
typedef struct ILOC_instruction{
	ILOC_op_t operation;
	ILOC_operand_list *operand_font;
	ILOC_operand_target op_target;
} ILOC_instruction_t;

/*
* ILOC_instruction_list
* Uma lista de instruções pode ser um programa em ILOC podendo conter uma label para representar a lista de instruções
*/
typedef struct ILOC_instruction_list{
	ILOC_instrution instruction;
	struct ILOC_instruction_list * prox;
	ILOC_label_t label;
}ILOC_instruction_list_t;


#endif
