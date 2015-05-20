#include "cc_iloc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_ast.h"
#include "cc_tree.h"

/*labelControl=0;
registerControl=0;
rarp = "rarp";
rbss = "rbss";*/
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
ILOC_operand_list_t* insertIlocOperandElement(char* op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux,*newOperand;
	operandListAux=operandList;
	newOperand = (ILOC_operand_list_t*)malloc(sizeof(struct ILOC_operand_list));
	newOperand->next= NULL;
	newOperand->op= op;
	if(operandList == NULL)
	{
		return newOperand;
	}
	else
	{
		while(operandListAux->next!=NULL)
		{
			operandListAux=operandListAux->next;		
		}
		operandListAux->next= newOperand;	
	}
	return operandList;
}


/*
* deleteIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* deleta elemento da lista de operandos
*/
ILOC_operand_list_t* deleteIlocOperandElement (char* op,ILOC_operand_list_t* operandList)
{
	ILOC_operand_list_t* operandListAux,*deletedOperand;
	operandListAux=operandList;
	if(operandListAux == NULL)
	{
		return NULL;
	}
	else
	{
		if(operandListAux->op == op)
		{
			deletedOperand = operandList;
			if(operandList->next!=NULL)
			{
				operandList= operandList->next;
				free(deletedOperand);
			}
			else
			{	
				operandList=NULL;
				free(deletedOperand);
			}	
			return operandList;
		}
		else
		{
			while(operandListAux->next !=NULL)
			{
				operandListAux= operandListAux->next;
				if(operandListAux->next->op == op)
				{
					deletedOperand= operandListAux->next;
					operandListAux->next= deletedOperand->next;
					deletedOperand->next = NULL;
					free(deletedOperand);
				}
			}

		}
		return operandList;
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
	return operandListAux;
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
	if(operandListSrc==NULL)
		return NULL;
	while(operandListSrcAux != NULL && operandListSrcAux->op != NULL && operandListSrcAux->op != NULL)
	{
		newOperandList = insertIlocOperandElement(operandListSrcAux->op,newOperandList);
		operandListSrcAux = operandListSrcAux->next;
	}
	return newOperandList;
}


/*
* newInstruction
* entrada: ILOC_op_t, ILOC_operand, ILOC_operand, ILOC_operand, ILOC_operand
* criação de uma nova instrução
*/
ILOC_instruction_t * newInstruction(ILOC_op_t operation,char* operand_src1,char* operand_src2, char* operand_dst1,char*operand_dst2 )
{
	ILOC_instruction_t *instruction;
	instruction= (ILOC_instruction_t*)malloc(sizeof(struct ILOC_instruction));
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
			if(operand_src1=NULL && operand_src2!=NULL && operand_dst1=NULL)
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
			if(operand_src1=NULL && operand_dst1=NULL)
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
			if(operand_src1=NULL && operand_dst1!=NULL)
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
			if(operand_dst1!=NULL)
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
			if(operand_src1=NULL && operand_dst1!=NULL)
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
			if(operand_src1!=NULL && operand_dst1!=NULL && operand_dst2!=NULL)
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
			if(operand_dst1!=NULL)
			{
				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_jump:
		{
			if(operand_dst1!=NULL)
			{

				instruction->operand_dst_list = insertIlocOperandElement(operand_dst1,instruction->operand_dst_list);
				break;
			}
			else 
				return NULL;
		}
		case op_cbr:
		{
			if(operand_src1!=NULL && operand_dst1!=NULL && operand_dst2!=NULL)
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
	ILOC_instruction_list_t* instructionListAux, *newInstruction;
	newInstruction = malloc(sizeof(struct ILOC_instruction_list));
	newInstruction->instruction.operation= instruction->operation;
	newInstruction->instruction.operand_src_list= copyOperandList(instruction->operand_src_list);
	newInstruction->instruction.operand_dst_list= copyOperandList(instruction->operand_src_list);
	newInstruction->label = label;
	newInstruction->next= NULL;
	if(instructionList == NULL)
	{
		return newInstruction;
	}
	else
	{
		instructionListAux=instructionList;
		while(instructionListAux->next!=NULL)
		{
			instructionListAux=instructionListAux->next;		
		}
		instructionListAux->next = newInstruction;
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
		deletedInstruction = instructionList;
		if(instructionList->next!=NULL)
		{
			instructionList= instructionList->next;
			free(deletedInstruction);
		}
		else
		{	
			instructionList=NULL;
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
	return instructionListAux;
}

/*
*Função createRegister: void -> ILOC_register_t
*Cria uma registrador novo baseado nas regra de ILOC
*Retorna um novo Registrador 
*/
ILOC_register_t createRegister()
{
	
	char prefix[2]="r", sufix[15]={ };
	ILOC_register_t newRegister=malloc(strlen(prefix)+strlen(sufix));; 
	sprintf(sufix,"%d",registerControl);
	registerControl++;
	strcpy(newRegister,prefix);
	strcat(newRegister,sufix);
	return newRegister;
}

/*
* Função createLabel entrada: void -> ILOC_label_t:
* A função serve para criar uma label de acordo com as regras da linguagem iloc
* Retorna uma label nova
*/
ILOC_label_t createLabel()
{
	char prefix[2]="L", sufix[15]={ };
	ILOC_register_t newLabel=malloc(strlen(prefix)+strlen(sufix));; 
	sprintf(sufix,"%d",labelControl);
	labelControl++;
	strcpy(newLabel,prefix);
	strcat(newLabel,sufix);
	return newLabel;
}

/*
* função: code_program
* Entrada: comp_tree_t Saída: void
* Gera código a partir da ast caso o código seja program
*/
void code_program(comp_tree_t **ast) {
	comp_dict_item_t *Program = (*ast)->tableItem;
	comp_tree_t *FirstChild = (*ast)->childNodeList->firstNode;

	if(FirstChild) 
	{
		comp_dict_item_t *FirstChildDict = FirstChild->tableItem;
		code_ger(&FirstChild); // recurção para a geração de código para filho do programa

	    ILOC_instruction_list_t *instructionLst= createIlocInstructionsList();
	    ILOC_instruction *inst;
	    char* label = createLabel();
	    inst= newInstruction(op_jumpI,NULL,NULL,label,NULL);
	    instructionLst = insertIlocInstructionsElement(inst,NULL,instructionLst);
	    /* dar apend no código de cada nodo
		*/
	}
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