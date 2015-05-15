#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_iloc.h"


/*
* createIlocOperandList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de operandos ILOC para as instruções
*/
ILOC_operand_list_t* createIlocOperandList()
{
	return NULL;
}

/*
* insertIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* insere um elemento na lista de operandos
*/
ILOC_operand_list_t* insertIlocOperandElement(union ILOC_operand op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux;
	operandListAux=operandList;
	if(operandListAux == NULL)
	{
		operandListAux = malloc(sizeof(struct ILOC_operand_list));
		operandListAux->op= op;
		operandListAux->next= NULL;
	}
	else
	{
		while(operandListAux!=NULL)
		{
			operandListAux=operandListAux->next;		
		}
		operandListAux = malloc(sizeof(struct ILOC_operand_list));
		operandListAux->op= op;
		operandListAux->next= NULL;
	}
	return operandList;
}

/*
* deleteIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* deleta elemento da lista de operandos
*/
ILOC_operand_list_t* deleteIlocOperandElement (union ILOC_operand op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux,*deletedOperand;
	operandListAux=operandList;
	if(operandListAux == NULL)
	{
		return NULL;
	}
	else
	{
		if(operandListAux->op.reg == op.reg ||operandListAux->op.label == op.label || operandListAux->op.val == op.val)
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
				if(operandListAux->next->op.reg == op.reg ||operandListAux->next->op.label == op.label || operandListAux->next->op.val == op.val)
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
		operandListAux=deleteIlocOperandElement(operandListAux->op,operandListAux);
	}
	return operandList;
}


/*
* newInstruction
* entrada: ILOC_op_t, ILOC_operand, ILOC_operand, ILOC_operand, ILOC_operand
* criação de uma nova instrução
*/
ILOC_instruction_t * newInstruction(ILOC_op_t operation,union ILOC_operand operand_src1,union ILOC_operand operand_src2, union ILOC_operand operand_dst1,union ILOC_operand operand_dst2 )
{
	ILOC_instruction_t *instruction;
	instruction= malloc(sizeof(struct ILOC_instruction));
	instruction->operation = operation;
	instruction->operand_src_list= createIlocOperandList();
	instruction->operand_dst_list= createIlocOperandList();
	switch(operation)
	{
		case op_add:
		case op_sub:
		case op_mult:
		case op_div:
		case op_lshift:
		case op_rshift:
		case op_and:
		case op_or:
		case op_xor:
		case op_loadA0:
		case op_cloadA0:
		case op_cmp_LT: 
		case op_cmp_LE:
		case op_cmp_EQ:
		case op_cmp_GE:
		case op_cmp_GT: 
		case op_cmp_NE:
		{ 	
			if(operand_src1.reg!=NULL && operand_src2.reg!=NULL && operand_dst1.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_src_list = insertIlocOperandElement(operand_src2,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_addI:
		case op_subI:
		case op_rsubI:
		case op_multI:
		case op_rdivI:
		case op_divI:
		case op_lshiftI:
		case op_rshiftI:
		case op_andI:
		case op_orI:
		case op_xorI:
		case op_loadAI:
		case op_cloadAI:
		{
			if(operand_src1.reg!=NULL && operand_dst1.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_src_list = insertIlocOperandElement(operand_src2,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_load:
		case op_cload:
		case op_store:
		case op_cstore:
		case op_i2i:
		case op_c2c:
		case op_c2i:
		case op_i2c:
		{
			if(operand_src1.reg!=NULL && operand_dst1.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_loadI:
		{
			if(operand_dst1.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_storeAI:
		case op_cstoreAI:
		{
			if(operand_src1.reg!=NULL && operand_dst1.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst2,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_storeA0:
		case op_cstoreA0:
		{
			if(operand_src1.reg!=NULL && operand_dst1.reg!=NULL && operand_dst2.reg!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst2,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_jumpI:
		{
			if(operand_dst1.label!=NULL)
			{
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_jump:
		{
			if(operand_dst1.reg!=NULL)
			{
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_cbr:
		{
			if(operand_src1.reg!=NULL && operand_dst1.label!=NULL && operand_dst2.label!=NULL)
			{
				instruction->operand_src_list = insertIlocOperandElement(operand_src1,instruction->operand_src_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst2,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		default: 
			return NULL;
	}
	return instruction;
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
		instructionListAux = malloc(sizeof(struct ILOC_instruction_list));
		instructionListAux->instruction.operation= instruction->operation;
		//instructionListAux->instruction->operand_src_list= instruction->operand_src;
		//instructionListAux->instruction->operand_dst_list= instruction->operand_dst;
		instructionListAux->label = label;
		instructionListAux->next= NULL;
	}
	else
	{
		while(instructionListAux!=NULL)
		{
			instructionListAux=instructionListAux->next;		
		}
		instructionListAux = malloc(sizeof(struct ILOC_instruction_list));
		instructionListAux->instruction.operation= instruction->operation;
		//instructionListAux->instruction->operand_src_list= instruction->operand_src;
		//instructionListAux->instruction->operand_targe_listt= instruction->operand_dst;
		instructionListAux->label = label;
		instructionListAux->next= NULL;
	}
	return instructionList;
}

/*
* deleteIlocInstructionsElement
* entrada: ILOC_instruction_t saída: ILOC_instruction_list_t
* deleta elemento da lista de instruções
*/
ILOC_instruction_list_t* deleteIlocInstructionsFirstElement(ILOC_instruction_list_t* instructionList)
{
	ILOC_instruction_list_t* instructionListAux,*deletedInstruction;
	instructionListAux=instructionList;
	if(instructionListAux == NULL)
	{
		return NULL;
	}
	else
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
		return instructionList;
	}
}

/*
* destroyIlocinstructionList
* entrada: void, saida: ILOC_operand_list_t	
* destroi a lista de operandos de ILOC por completo
*/
ILOC_instruction_list_t* destroyIlocInstructionList(ILOC_instruction_list_t* instructionList)
{
	ILOC_instruction_list_t* instructionListAux;
	instructionListAux = instructionList;
	while(instructionListAux !=NULL)
	{
		instructionListAux=deleteIlocInstructionsFirstElement(instructionListAux);
	}
	return instructionList;
}

/*
*Função createRegister: void -> ILOC_register_t
*Cria uma registrador novo baseado nas regra de ILOC
*Retorna um novo Registrador 
*/
ILOC_register_t createRegister()
{
	ILOC_register_t newRegister;
	char *prefix,*sufix;
	prefix = "r";
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
	prefix = "L";
	sprintf(sufix, "%d", labelControl); 
	labelControl++;
	newLabel= strcat(prefix,sufix);
	return newLabel;
}