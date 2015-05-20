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
					deletedOperand= operandListAux->next
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
			deletedInstruction->operand_src_list = destroyIlocOperandList(deletedInstruction->operand_src_list);
			deletedInstruction->operand_dst_list = destroyIlocOperandList(deletedInstruction->operand_dst_list);
			free(deletedInstruction);
		}
		else
		{	
			instructionList=NULL;
			deletedInstruction->operand_src_list = destroyIlocOperandList(deletedInstruction->operand_src_list);
			deletedInstruction->operand_dst_list = destroyIlocOperandList(deletedInstruction->operand_dst_list);
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
	    Program->code= concatIlocInstructionsList(Program->code,instructionLst);
	}
}


void code_literal(comp_tree_t **ast) {
	comp_dict_item_t *S = (*ast)->tableItem;

  	ILOC_instruction_list_t *instructionLst= createIlocInstructionsList();
	ILOC_instruction *inst;
  
  	switch(S->iks_type) {
	    /*falta booleanos*/
    case SIMBOLO_LITERAL_INT:
	    	S->tempName = createRegister();
	    	inst= newInstruction(op_loadI,S->key,NULL,S->tempName,NULL,NULL);
	    	instructionLst= insertIlocInstructionsElement(inst,NULL,instructionLst);
	      	S->code=concatIlocInstructionsList(S->code,instructionLst);
	    	break;
	    case SIMBOLO_LITERAL_FLOAT:
	    	printf("code_literal para TK_LIT_FLOAT não implementado\n");
	    	break;
	    case SIMBOLO_LITERAL_CHAR:
	    	S->tempName = createRegister();
	    	inst= newInstruction(op_loadI,S->key,NULL,S->tempName,NULL,NULL);
	    	instructionLst= insertIlocInstructionsElement(inst,NULL,instructionLst);
	      	S->code=concatIlocInstructionsList(S->code,instructionLst);
	    	break;
	    case SIMBOLO_LITERAL_STRING:
				code_id_lits(ast);
				break;
	    default:
	      fprintf(stderr,"error at code_literal: token type: %d\n",S->symbol->token_type);
	  }
}

void code_id_lits(comp_tree_t **ast) {
	comp_dict_item_t *E = (*ast)->tableItem;

	// register that will receive memory content of id
	E->tempName = createRegister();

	// register that will receive the address of this id
	char *reg_temp = createRegister();

	char addr[10];
	sprintf(addr,"%d",E.size);

	ILOC_instruction_t *load,*loadAI;
	ILOC_instruction_list_t *instLst=createIlocInstructionsList();
	ILOC_register_t offset_reg;
	/*if (==) {
		offset_reg=rarp;
	}
	else {
		offset_reg=rbss;
	}*/
	loadAI = newInstruction(op_loadAI,offset_reg,addr,reg_temp,NULL);
	instLst=insertIlocInstructionsElement(loadAI,NULL,instLst);

	// loading memory content to register E->temp.name
	switch(E->iks_type) {
		case IKS_INT:
			load = newInstruction(op_load,reg_temp,NULL,E->tempName,NULL);
			instLst=insertIlocInstructionsElement(load,NULL,instLst);
			break;
		
		case IKS_CHAR:
			load = newInstruction(op_load,reg_temp,NULL,E->tempName,NULL);
			instLst=insertIlocInstructionsElement(load,NULL,instLst);
			break;	
	}	
	E->code=concatIlocInstructionsList(E->code,instLst);
}

void code_arit_sum(comp_tree_t **ast) {
	
	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	code_ger(&E1t);

	comp_tree_t *E2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *E2 = E2t->tableItem;
	code_ger(&E2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(E1->code,E2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *arit_sum = createIlocInstructionsList();

	ILOC_instruction_t *art_sum = newInstruction(op_add,E1->tempName,E2->tempName,B->tempName,NULL);
	arit_sum=insertIlocInstructionsElement(art_sum,NULL,arit_sum);
	B->code = concatIlocInstructionsList(B->code,arit_sum);	
}


void code_arit_sub(comp_tree_t **ast) {
	
	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	code_ger(&E1t);

	comp_tree_t *E2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *E2 = E2t->tableItem;
	code_ger(&E2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(E1->code,E2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *arit_sub = createIlocInstructionsList();

	ILOC_instruction_t *art_sub = newInstruction(op_sub,E1->tempName,E2->tempName,B->tempName,NULL);
	arit_sub=insertIlocInstructionsElement(art_sub,NULL,arit_sub);
	B->code = concatIlocInstructionsList(B->code,arit_sub);	
}


void code_arit_mul(comp_tree_t **ast) {
	
	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	code_ger(&E1t);

	comp_tree_t *E2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *E2 = E2t->tableItem;
	code_ger(&E2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(E1->code,E2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *arit_mul = createIlocInstructionsList();

	ILOC_instruction_t *art_mul = newInstruction(op_mult,E1->tempName,E2->tempName,B->tempName,NULL);
	arit_mul=insertIlocInstructionsElement(art_mul,NULL,arit_mul);
	B->code = concatIlocInstructionsList(B->code,arit_mul);	
}


void code_arit_div(comp_tree_t **ast) {
	
	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	code_ger(&E1t);

	comp_tree_t *E2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *E2 = E2t->tableItem;
	code_ger(&E2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(E1->code,E2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *arit_div = createIlocInstructionsList();

	ILOC_instruction_t *art_div = newInstruction(op_div,E1->tempName,E2->tempName,B->tempName,NULL);
	arit_div=insertIlocInstructionsElement(art_div,NULL,arit_div);
	B->code = concatIlocInstructionsList(B->code,arit_div);
}

void code_arim_inv(comp_tree_t **ast) 
{
	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	code_ger(&E1t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->tempName = createRegister();

	ILOC_instruction_list_t *arit_inv = createIlocInstructionsList();

	ILOC_instruction_t *art_inv = newInstruction(op_mult,E1->tempName,"-1",B->tempName,NULL);
	arit_inv=insertIlocInstructionsElement(art_inv,NULL,arit_inv);
	B->code = concatIlocInstructionsList(B->code,arit_inv);
}

void code_attr(comp_tree_t **ast) {
	comp_dict_item_t *S = (*ast)->tableItem;
	S->tempNext = createLabel();
	
	struct nodeList_t *first_child_in_list = (*ast)->childNodeList;
	struct nodeList_t *second_child_in_list = (*ast)->childNodeList->nextNode;
	struct nodeList_t *third_child_in_list = (*ast)->childNodeList->nextNode->nextNode;
	
	comp_tree_t *IDorIDV_tree = first_child_in_list->firstNode; 
	comp_dict_item_t *IDorIDV = IDorIDV_tree->tableItem;

	comp_tree_t *Et = (*ast)->childNodeList->nextNode->firstNode;
	comp_dict_item_t *E = Et->tableItem;
	code_ger(&Et);
	
	S->code = concatIlocInstructionsList(S->code,E->code);

	ILOC_instruction_t *attr;
	ILOC_instruction_list_t instLst = createIlocInstructionsList();
	if(IDorIDV->type == IKS_AST_VETOR_INDEXADO) {
		comp_dict_item_t *ID = (comp_dict_item_t *)IDorIDV_tree->childNodeList->firstNode;
		code_ger(&IDorIDV_tree);
		S->code = concatIlocInstructionsList(S->code,IDorIDV->code);
		
		char *offset_reg = NULL;
		
		attr =newInstruction(op_storeAI,E->tempName,NULL,offset_reg,IDorIDV->tempName);
		instLst= insertIlocInstructionsElement(attr,NULL,instLst);
	}
	else {
		comp_dict_item_t *ID = IDorIDV;
		char addr[10];
		sprintf(addr,"%d",E.size);
		
		char *offset_reg = NULL;
		// ver offset
		attr =newInstruction(op_storeAI,E->tempName,NULL,offset_reg,addr);
		instLst= insertIlocInstructionsElement(attr,NULL,instLst);
	}
	
	S->code = concatIlocInstructionsList(S->code,instLst);
	
	if(third_child_in_list != first_child_in_list) {
		code_ger((comp_tree_t**)&third_child_in_list->firstNode);
		comp_dict_item_t *next_command_tree = ((comp_tree_t *)third_child_in_list->firstNode)->tableItem;
		S->code = concatIlocInstructionsList(S->code,next_command_tree->code);
	}
	
}

void code_comp_equal(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_eq = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_equal = newInstruction(op_cmp_EQ,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_eq=insertIlocInstructionsElement(logic_comp_equal,NULL,logic_comp_eq);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_eq=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_eq);
	B->code=concatIlocInstructionsList(B->code,logic_comp_eq);
}

void code_comp_dif(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_dif = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_different = newInstruction(op_cmp_NE,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_eq=insertIlocInstructionsElement(logic_comp_different,NULL,logic_comp_dif);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_different=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_dif);
	B->code=concatIlocInstructionsList(B->code,logic_comp_dif);
}

void code_comp_GreaterEqual(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_GE = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_GreaterEqual = newInstruction(op_cmp_GE,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_GE=insertIlocInstructionsElement(logic_comp_GreaterEqual,NULL,logic_comp_GE);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_GE=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_GE);
	B->code=concatIlocInstructionsList(B->code,logic_comp_GE);
}

void code_comp_GreaterThan(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_GT = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_greaterThan = newInstruction(op_cmp_GT,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_GT=insertIlocInstructionsElement(logic_comp_greaterThan,NULL,logic_comp_GT);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_GT=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_GT);
	B->code=concatIlocInstructionsList(B->code,logic_comp_GT);
}

void code_comp_LowerEqual(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_LE = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_lowerEqual = newInstruction(op_cmp_LE,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_LE=insertIlocInstructionsElement(logic_comp_lowerEqual,NULL,logic_comp_LE);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_LE=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_LE);
	B->code=concatIlocInstructionsList(B->code,logic_comp_LE);
}

void code_comp_LowerThan(comp_tree_t** ast)
{	
	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	code_ger(&B2t);

	comp_dict_item_t *B = (*ast)->tableItem;
	B->code = concatIlocInstructionsList(E1->code,E2->code);
	B->tempName = createRegister();

	ILOC_instruction_list_t *logic_comp_LT = createIlocInstructionsList();

	B->tempBT= createLabel();
	B->tempBF= createLabel();
	ILOC_instruction_t *logic_comp_lowerThan = newInstruction(op_cmp_EQ,B1->tempName,B2->tempName,B->tempName,NULL);
	logic_comp_LT=insertIlocInstructionsElement(logic_comp_lowerThan,NULL,logic_comp_LT);
	ILOC_instruction_t *conditionalJump = newInstruction(op_cbr,B->tempName,NULL,B->tempBT,B->tempBF);
	logic_comp_LT=insertIlocInstructionsElement(conditionalJump,NULL,logic_comp_LT);
	B->code=concatIlocInstructionsList(B->code,logic_comp_LT);
}

void code_neg(comp_tree_t** ast)
{
	comp_dict_item_t *B = (*ast)->item;

	comp_tree_t *E1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *E1 = E1t->tableItem;
	E1->tempBT = B->tempBF;
	E1->tempBF = B->tempBT;
	code_ger(&E1t);
	B->code = E1->code;	

}


void code_and(comp_tree_t** ast)
{	
	comp_dict_item_t *B = (*ast)->tableItem;
	B->tempName = createRegister();

	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	B1->tempBT=createLabel();
	B1->tempBF=B->tempBF;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	B2->tempBT=B->tempBT;
	B2->tempBF=B->tempBF;
	code_ger(&B2t);

	B2->code->label= B1->tempBT;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
}

void code_or(comp_tree_t** ast)
{	
	comp_dict_item_t *B = (*ast)->tableItem;
	B->tempName = createRegister();

	comp_tree_t *B1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B1 = B1t->tableItem;
	B1->tempBT=createLabel();
	B1->tempBF=B->tempBF;
	code_ger(&B1t);

	comp_tree_t *B2t = (*ast)->childNodeList->next->firstNode;
	comp_dict_item_t *B2 = B2t->tableItem;
	B2->tempBT=B->tempBT;
	B2->tempBF=B->tempBF;
	code_ger(&B2t);

	B2->code->label= B1->tempBF;
	B->code = concatIlocInstructionsList(B1->code,B2->code);
}

void code_if_else(comp_tree_t **ast) {
	comp_dict_item_t *S = (*ast)->tableItem;
	S->tempNext = createLabel();

	comp_tree_t *Bt = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B = Bt->tableItem;
	B->tempBT= createLabel();
	B->tempBF = createLabel();
	code_ger(&Bt);

	comp_tree_t *S1t = (*ast)->childNodeList->nextNode->firstNode;
	comp_dict_item_t *S1 = S1t->tableItem;
	S1->tempNext = S->tempNext;
	code_ger(&S1t);

	if((*ast)->childNodeList->nextNode->nextNode != NULL)
	{
		comp_tree_t *S2t = (*ast)->childNodeList->nextNode->nextNode->firstNode;
		comp_dict_item_t *S2 = S2t->tableItem;
		S2->tempNext = S->tempNext;
		code_ger(&S2t);
	}
	S1->code->label= B->tempBT;
	S->code = concatIlocInstructionsList(B->code,S1->code);
	ILOC_instruction_t *goto_S_next= newInstruction(op_jumpI,NULL,NULL,S->tempNext,NULL);
	S->code=insertIlocInstructionsElement(goto_S_next,NULL,S->code);
	S2->code->label=B->tempBF;
	S->code = concatIlocInstructionsList(S->code,S2->code);
	S->code->label=S->tempNext;
	if((*ast)->childNodeList->nextNode->nextNode->nextNode!=NULL) {
		comp_tree_t *Stnext = (*ast)->childNodeList->nextNode->nextNode->nextNode->firstNode;
		code_ger(&Stnext);
		comp_dict_item_t *Snext = Stnext->tableItem;
		S->code = concatIlocInstructionsList(S->code,Snext->code);
	}
}



void code_while_do(comp_tree_t **ast) 
{
	comp_dict_item_t *S = (*ast)->tableItem;
	S->tempNext = createLabel();

	comp_tree_t *Bt = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *B = Bt->tableItem;
	B->tempBT = createLabel();
	B->tempBF = S->tempNext;
	code_ger(&Bt);

	comp_tree_t *S1t = (*ast)->childNodeList->nextNode->firstNode;
	comp_dict_item_t *S1 = S1t->tableItem;
	S->tempBegin = createLabel();
	S1->tempNext = S->tempBegin;
	code_ger(&S1t);

  	B->code->label=S->tempBegin;
	S->code = concatIlocInstructionsList(S->code,B->code);

  	S1->code->label=B->tempBT;
	S->code = concatIlocInstructionsList(S->code,S1->code);

	ILOC_instruction_t *goto_S_next= newInstruction(op_jumpI,NULL,NULL,S->tempBegin,NULL);
	S->code=insertIlocInstructionsElement(goto_S_next,NULL,S->code);
  	
	S->code->label=S->tempNext;

	// if there is next command
	if((*ast)->childNodeList->nextNode->nextNode!=NULL) {
		comp_tree_t *Stnext = (*ast)->childNodeList->nextNode->nextNode->nextNode->firstNode;
		code_ger(&Stnext);
		comp_dict_item_t *Snext = Stnext->tableItem;
		S->code = concatIlocInstructionsList(S->code,Snext->code);
	}
}
void code_do_while(comp_tree_t **ast) 
{
	comp_dict_item_t *S = (*ast)->tableItem;
	S->tempNext = createLabel();

	comp_tree_t *S1t = (*ast)->childNodeList->firstNode;
	comp_dict_item_t *S1 = S1t->tableItem;
	S->tempBegin = createLabel();
	S1->tempNext = createLabel();
	code_ger(&S1t);

	comp_tree_t *Bt = (*ast)->childNodeList->nextNode->firstNode;
	comp_dict_item_t *B = Bt->tableItem;
	B->tempBT = S->tempBegin;
	B->tempBF = S->tempNext;
	code_ger(&Bt);

  	S1->code->label=S->tempBegin;
	S->code = concatIlocInstructionsList(S->code,S1->code);

  	B->code->label=S1->tempNext;
	S->code = concatIlocInstructionsList(S->code,B->code);

	S->code->label=S->tempNext;

	if((*ast)->childNodeList->nextNode->nextNode!=NULL) {
		comp_tree_t *Stnext = (*ast)->childNodeList->nextNode->nextNode->nextNode->firstNode;
		code_ger(&Stnext);
		comp_dict_item_t *Snext = Stnext->tableItem;
		S->code = concatIlocInstructionsList(S->code,Snext->code);
	}
}

void code_vector(comp_tree_t **ast) {
	comp_dict_item_t *IDn = ((comp_tree_t *)(*ast)->childNodeList->firstNode)->tableItem;
	iks_grammar_symbol_t *IDs = IDn->symbol;
	
	ILOC_instruction_t *vector_code = createIlocInstructionsList();
	
	/*char *dk_reg = get_dk_reg(*ast, IDs->num_dimen, &vector_code);*/

	char w[5]; 
	sprintf(w,"%d",IDs->iks_size);
	char *w_reg = createRegister();
	ILOC_instruction_t = w_load = newInstruction(op_loadI,w,NULL,w_reg,NULL);
	insertIlocInstructionsElement(w_load,NULL,vector_code);
	
	ILOC_instruction_t *multiply = newInstruction(op_mult,dk_reg,w_reg,dk_reg,NULL);
	insertIlocInstructionsElement(multiply,NULL,vector_code);
	
	char base[5];
	sprintf(base,"%d",IDs->addr_offset);
	char *base_reg = createRegister();
	ILOC_instruction_t *base_load = newInstruction(op_loadI,base,NULL,base_reg,NULL);
	insertIlocInstructionsElement(base_load,NULL,vector_code);

	ILOC_instruction_t *add =  newInstruction(op_add,base_reg,dk_reg,dk_reg,NULL);
	iks_list_append(add,NULL,vector_code);
	
	comp_dict_item_t *IDVn = (*ast)->item;
	IDVn->code = vector_code;
	IDVn->tempName = dk_reg;
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
void ilocPrintInstructionLst(ILOC_instruction_list_t *instructions) {
	ILOC_instruction_list_t *it;
	it = instructions;
	do 
	{
		ILOC_instruction_t *inst = it->instruction;
		if (!inst) 
			break;
	    if(inst->operation!=op_nop) 
	  		printf("\t");
		switch(inst->operation) {
			case op_nop:
				break;
			case op_inc:
				printf("inc %s",inst->operand_src_list->op);
				break;
			case op_dec:
				printf("dec %s",inst->operand_src_list->op);
				break;
			case op_tbl:
				printf("tbl %s, %s",inst->operand_src_list->op,inst->operand_src_list->next->op);
				break;
			case op_add:
				printf("add %s, %s => %s",inst->operand_src_list->inst,inst->operand_src_list->next->inst,inst->operand_dst_list->op);
				break;
			case op_addI:
				printf("addI %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_multI:
				printf("multI %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_sub:
				printf("sub %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_subI:
				printf("subI %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->inst,inst->operand_dst_list->op);
				break;
			case op_mult:
				printf("mult %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_div:
				printf("div %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_inv:
				printf("inv %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_divI:
				printf("divI %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_jump:
				printf("jump -> %s",inst->operand_dst_list->op);
				break;
			case op_jumpI:
				printf("jumpI -> %s",inst->operand_dst_list->op);
				break;
			case op_cmp_LT:
				printf("cmp_LT %s, %s -> %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cmp_LE:
				printf("cmp_LE %s, %s -> %s",inst->operand_src_list->inst,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cmp_EQ:
				printf("cmp_EQ %s, %s -> %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cmp_GE:
				printf("cmp_GE %s, %s -> %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cmp_GT:
				printf("cmp_GT %s, %s -> %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cmp_NE:
				printf("cmp_NE %s, %s -> %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
				break;
			case op_cbr:
				printf("cbr %s -> %s, %s",inst->operand_src_list->op,inst->operand_dst_list->op,inst->operand_dst_list->next->op);
				break;
		    case op_loadAI:
		      	printf("loadAI %s, %s => %s",inst->operand_src_list->op,inst->operand_src_list->next->op,inst->operand_dst_list->op);
		      	break;
		    case op_loadI:
		   		printf("loadI %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		      	break;
		    case op_load:
		        printf("load %s => %s",	inst->operand_src_list->op,inst->operand_dst_list->op);
		        break;
		    case op_cload:
		      	printf("cload %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		      	break;
		    case op_i2i:
		        printf("i2i %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		        break;
		    case op_i2c:
		        printf("i2c %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		        break;
		    case op_c2i:
		        printf("c2i %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		        break;
		    case op_c2c:
		        printf("c2c %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
		        break;
		    case op_store:
		      	printf("store %s => %s",inst->operand_src_list->op,inst->operand_dst_list->op);
				break;
	      	case op_storeAI:
		      	printf("storeAI %s => %s, %s",inst->operand_src_list->op,inst->operand_dst_list->op,inst->operand_dst_list->next->op);
				break;
			default:
				fprintf(stderr,"error at iloc_oper_print: op code: %d\n",inst->operation);
	    }
	    
	    if(inst->operation!=op_nop) {
	      printf("\n");
	    }

	    it = it->next;    
	} while(it != instructions);
}