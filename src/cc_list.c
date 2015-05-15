#include <stdio.h>
#include <stdlib.h>
#include "cc_list.h"
#include "cc_iloc.h"

/*
* createIlocOperandList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de operandos ILOC para as instruções
*/
ILOC_instruction_list_t* createIlocOeprandList(void)
{
	return NULL;
}

/*
* insertIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* insere um elemento na lista de operandos
*/
ILOC_operand_list_t* insertIlocOperandElement(ILOC_operand op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux;
	operandListAux=operandList;
	if(operandListAux == NULL)
	{
		operandListAux = malloc(sizeof(struct ILOC_operand_list_t));
		operandListAux.op= op;
		operandListAux->next= NULL;
	}
	else
	{
		while(operandListAux!=NULL)
		{
			operandListAux=operandListAux->next;		
		}
		operandListAux = malloc(sizeof(struct ILOC_operand_list_t));
		operandListAux.op= op;
		operandListAux->next= NULL;
	}
	return operandList;
}

/*
* deleteIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* deleta elemento da lista de operandos
*/
ILOC_operand_list_t* deleteIlocOperandElement (ILOC_operand op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux,*deletedOperand;
	operandListAux=operandList;
	if(operandListAux == NULL)
	{
		return NULL;
	}
	else
	{
		if(operandListAux.op == op)
		{
			deletedOperand = operandListAux;
			if(operandListAux->next!=NULL)
			{
				operandListAux= operandListAux->next;
				operandList= operandList->next;
				free(deletedOperand);
			}
			else
			{	
				operandListAux=NULL;
				free(deletedOperand);
			}	
		}
		else
		{
			while(operandListAux->next !=NULL)
			{
				operandListAux= operandListAux->next;
				if(operandListAux->next.op == op)
				{
					deletedOperand= operandListAux->next;
					operandListAux->next= deletedOperand->next;
					deletedOperand->next = NULL;
					free(deletedOperand);
				}
			}

		}
		return operandListAux;
	}
}

/*
* destroyIlocOperandList
* entrada: void, saida: ILOC_operand_list_t	
* destroi a lista de operandos de ILOC por completo
*/
ILOC_operand_list_t* destroyIlocOperandList(ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux;
	operandListAux= operandList;
	while(operandListAux !=NULL)
	{
		operandListAux=deleteIlocInstructionsElement(operandListAux.op,operandListAux);
	}
	return operandList;
}


/*
* newInstruction
* entrada: ILOC_op_t, ILOC_operand, ILOC_operand, ILOC_operand, ILOC_operand
* criação de uma nova instrução
*/
ILOC_instruction_t * newInstruction(ILOC_op_t operation,ILOC_operand *operand_font1,ILOC_operand *operand_font2, ILOC_operand *operand_target1, ILOC_operand *operand_target2)
{
	ILOC_instruction_t *newInstruction;
	newInstruction= malloc(sizeof(struct ILOC_instruction));
	newInstruction.operation = operation;
	struction->operand_font1= createIlocOeprandList();
	if(operand_font1!=NULL)
		instruction->operand_font_list = insertIlocOperandElement(operand_font1,instruction->operand_font_list);
	if(operand_font2!=NULL)
		instruction->operand_font_list = insertIlocOperandElement(operand_font2,instruction->operand_font_list);
	struction->operand_font= createIlocOeprandList();
	if(operand_target1!=NULL)
		instruction->operand_target_list = insertIlocOperandElement(operand_target1,instruction->operand_target_list);
	if(operand_target2!=NULL)
		instruction->operand_target_list = insertIlocOperandElement(operand_target2,instruction->operand_target_list);
	return newInstruction;
}




/*
* createIlocInstructionsList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de instruções ILOC
*/
ILOC_instruction_list_t* createIlocInstructionsList(void)
{
	return NULL;
}


/*
* insertIlocInstructionsElement
* entrada: ILOC_instruction_t, ILOC_label_t saída: ILOC_instruction_list_t
* insere um elemento na lista de instruções
*/
ILOC_instruction_list_t* insertIlocInstructionsElement(ILOC_instruction_t* instruction, ILOC_label_t label,ILOC_instruction_list_t* instructionList)
{
	ILOC_instruction_list_t* instructionListAux;
	instructionListAux=instructionList;
	if(instructionListAux == NULL)
	{
		instructionListAux = malloc(sizeof(struct ILOC_instruction_list_t));
		instructionListAux.instruction.operation= instruction->operation;
		instructionListAux.instruction->operand_font_list= instruction->operand_font;
		instructionListAux.instruction->operand_target_list= instruction->operand_target;
		instructionListAux.label->name = label->name;
		instructionListAux.label.pos = label->pos;
		instructionListAux->next= NULL;
	}
	else
	{
		while(instructionListAux!=NULL)
		{
			instructionListAux=instructionListAux->next;		
		}
		instructionListAux = malloc(sizeof(struct ILOC_instruction_list_t));
		instructionListAux.instruction.operation= instruction->operation;
		instructionListAux.instruction->operand_font_list= instruction->operand_font;
		instructionListAux.instruction->operand_targe_listt= instruction->operand_target;
		instructionListAux.label->name = label->name;
		instructionListAux.label.pos = label->pos;
		instructionListAux->next= NULL;
	}
	return instructionList;
}

/*
* deleteIlocInstructionsElement
* entrada: ILOC_instruction_t saída: ILOC_instruction_list_t
* deleta elemento da lista de instruções
*/
ILOC_instruction_list_t* deleteIlocInstructionsElement(ILOC_instruction_t instruction,ILOC_operand_list_t* instructionList)
{
	ILOC_instruction_list_t* instructionListAux,*deletedInstruction;
	instructionListAux=instructionList;
	if(instructionListAux == NULL)
	{
		return NULL;
	}
	else
	{
		if(instructionListAux.op == op)
		{
			deletedInstruction = instructionListAux;
			if(instructionListAux->next!=NULL)
			{
				instructionListAux= instructionListAux->next;
				instructionList= instructionList->next;
				free(deletedInstruction);
			}
			else
			{	
				instructionListAux=NULL;
				free(deletedInstruction);
			}	
		}
		else
		{
			while(instructionListAux->next !=NULL)
			{
				instructionListAux= instructionListAux->next;
				if(instructionListAux->next.op == op)
				{
					deletedInstruction= instructionListAux->next;
					instructionListAux->next= deletedInstruction->next;
					deletedInstruction->next = NULL;
					free(deletedInstruction);
					return instructionList;
				}
			}

		}
		return instructionList;
	}
}

/*
* destroyIlocinstructionList
* entrada: void, saida: ILOC_operand_list_t	
* destroi a lista de operandos de ILOC por completo
*/
ILOC_operand_list_t* destroyIlocInstructionList(ILOC_operand_list_t* instructionList)
{
	ILOC_operand_list_t* instructionListAux;
	instructionListAux= instructionList;
	while(instructionListAux !=NULL)
	{
		instructionListAux=deleteIlocInstructionsElement(instructionListAux.instruction,instructionListAux.label ,instructionListAux);
	}
	return instructionList;
}