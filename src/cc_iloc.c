#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_iloc.h"
#include "cc_ast.h"
#include "cc_tree.h"


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
* copyOperandList
* entrada: ILOC_operand_list_t saída: ILOC_operand_list_t
* copia a lista de operando para outra lista de operandos
* função utilizada para a lista de instruções
*/
ILOC_operand_list_t* copyOperandList(ILOC_operand_list_t* operandListSrc)
{
	ILOC_operand_list_t* operandListSrcAux, *newOperandList;
	newOperandList = createIlocOperandList();
	operandListSrcAux = operandListSrc;
	while(operandListSrcAux != NULL)
	{
		newOperandList = insertIlocOperandElement(operandListSrcAux->op,newOperandList);
		operandListSrcAux = operandListSrcAux->next;
	}
	return newOperandList;
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
ILOC_instruction_list_t* insertIlocInstructionsElement(ILOC_instruction_t *instruction, ILOC_label_t label,ILOC_instruction_list_t* instructionList)
{
	ILOC_instruction_list_t* instructionListAux;
	instructionListAux=instructionList;
	if(instructionListAux == NULL)
	{
		instructionListAux = malloc(sizeof(struct ILOC_instruction_list));
		instructionListAux->instruction.operation= instruction->operation;
		instructionListAux->instruction.operand_src_list= copyOperandList(instruction->operand_src_list);
		instructionListAux->instruction.operand_dst_list= copyOperandList(instruction->operand_src_list);
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
		instructionListAux->instruction.operand_src_list= copyOperandList(instruction->operand_src_list);
		instructionListAux->instruction.operand_dst_list= copyOperandList(instruction->operand_dst_list);
		instructionListAux->label = label;
		instructionListAux->next= NULL;
	}
	return instructionList;
}

/*
* concatIlocInstructionsList
* entrada: ILOC_instruction_t, ILOC_instruction_list_t saída: ILOC_instruction_list_t
* concatena duas listas de instruções 
*/
ILOC_instruction_list_t* concatIlocInstructionsList(ILOC_instruction_list_t* startList, ILOC_instruction_list_t* endList)
{
	ILOC_instruction_list_t* p;
	if(startList == NULL){
		if(endList == NULL)
			return NULL;
		return endList;
	}
	else
		if (endList == NULL)
			return startList;
		else
		{
			p=startList;
			while (p->next!=NULL)             
                p=p->next;
            p->next=endList;                            
            return startList;
		}
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

/*
* função: code_ger
* Entrada: comp_tree_t Saída: void
* Gera código a partir da ast
*/
void code_ger(comp_tree_t** ast)
{
	ILOC_instruction_list_t *code;
	code =createIlocInstructionsList();
	comp_dict_item_t *astNode;
	astNode = (*ast)->tableItem;
	
	switch(astNode->nodeType) {
		case AST_PROGRAMA:
			// caso o nodo seja a entrada do programa, a função do código do programa será realizado
		case AST_FUNCAO:
		case AST_IF_ELSE:
		case AST_DO_WHILE:
		case AST_WHILE_DO:
		case AST_INPUT:
		case AST_OUTPUT:
		case AST_ATRIBUICAO:
		case AST_RETURN:
		case AST_BLOCO:
		case AST_IDENTIFICADOR:
		case AST_LITERAL:
		case AST_ARIM_SOMA:
		case AST_ARIM_SUBTRACAO:
		case AST_ARIM_MULTIPLICACAO:
		case AST_ARIM_DIVISAO:
		case AST_ARIM_INVERSAO:
		case AST_LOGICO_E:
		case AST_LOGICO_OU:
		case AST_LOGICO_COMP_IGUAL:
		case AST_LOGICO_COMP_DIF:
		case AST_LOGICO_COMP_LE:
		case AST_LOGICO_COMP_GE:
		case AST_LOGICO_COMP_L:
		case AST_LOGICO_COMP_G:
		case AST_LOGICO_COMP_NEGACAO:
		case AST_VETOR_INDEXADO:
		case AST_CHAMADA_DE_FUNCAO:
		default:
			fprintf(stderr,"erro na geracao de código\n");
			break;
	}
}

/*
* 
*
*
*/