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
	ILOC_register_t r;
	ILOC_label_t L;
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
* createIlocOperandList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de operandos ILOC para as instruções
*/
ILOC_instruction_list_t* createIlocOperandList(ILOC_operand_list_t* operandList);

/*
* insertIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* insere um elemento na lista de operandos
*/
ILOC_operand_list_t* insertIlocOperandElement(ILOC_operand op, ILOC_operand_list_t* operandList);

/*
* deleteIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* deleta elemento da lista de operandos
*/
ILOC_operand_list_t* deleteIlocOperandElement(ILOC_operand op, ILOC_operand_list_t* operandList);

/*
* destroyIlocInstructionList
* entrada: void, saida: ILOC_operand_list_t	
* destroi a lista de operandos de ILOC por completo
*/
ILOC_operand_list_t* destroyIlocInstructionList(ILOC_operand_list_t* operandList);



/*
* ILOC_instruction_t
* Uma instrução possui uma operação, uma lista de operandos fontes e um operando alvo para o resultado da operação
*/
typedef struct ILOC_instruction{
	ILOC_op_t operation;
	ILOC_operand_list_t *operand_font_list;
	ILOC_operand_list_t *operand_target_list;
} ILOC_instruction_t;


/*
* newInstruction
* entrada: ILOC_op_t, ILOC_operand, ILOC_operand, ILOC_operand, ILOC_operand
* criação de uma nova instrução
*/
ILOC_instruction * newInstruction(ILOC_op_t op,ILOC_operand *operand_font1,ILOC_operand *operand_font2, ILOC_operand *operand_target1, ILOC_operand *operand_target2 ); 

/*
* ILOC_instruction_list
* Uma lista de instruções pode ser um programa em ILOC podendo conter uma label para representar a lista de instruções
*/
typedef struct ILOC_instruction_list{
	ILOC_instruction_t instruction;
	struct ILOC_instruction_list *prox;
	ILOC_label_t label;
}ILOC_instruction_list_t;

/*
* createIlocInstructionsList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de instruções ILOC
*/
ILOC_instruction_list_t* createIlocInstructionsList(void);

/*
* insertIlocInstructionsElement
* entrada: ILOC_instruction_t, ILOC_label_t saída: ILOC_instruction_list_t
* insere um elemento na lista de instruções
*/
ILOC_instruction_list_t* insertIlocInstructionsElement(ILOC_instruction_t instruction, ILOC_label_t label, ILOC_operand_list_t* instructionList);

/*
* deleteIlocInstructionsElement
* entrada: ILOC_instruction_t saída: ILOC_instruction_list_t
* deleta elemento da lista de instruções
*/
ILOC_instruction_list_t* deleteIlocInstructionsElement(ILOC_instruction_t instruction, ILOC_operand_list_t* instructionList);

/*
* destroyIlocInstructionList
* entrada: void, saida: ILOC_instruction_t	
* destroi a lista de instruções de ILOC por completo
*/
ILOC_instruction_list_t* destroyIlocInstructionList(ILOC_operand_list_t* instructionList);



#endif
