#ifndef __IKS_ILOC_H__
#define __IKS_ILOC_H__
#include "cc_ast.h"
#include "cc_tree.h"



int labelControl=0; // numero do próxima label, será utilizado para a criação de labels
int registerControl=0; // numero do próximo registrador, será utilizado para a criação de registradores

/*  
*Lista de operações possiveis na linguagem ILOC o enum serve para facilitar o acesso para a geração de código ILOC
*/
enum ILOC_op {
	op_nop = 0,	op_add=1,op_sub=2, op_mult=3, op_div=4,op_addI=5,op_subI=6,op_rsubI=7, op_multI=8, op_divI=9, 
	op_rdivI=10,op_lshift=11, op_lshiftI=12,op_rshift=13,op_rshiftI=14,op_and=15, op_andI=16, op_or=17, op_orI=18, 
	op_xor=19, op_xorI=20,op_loadI=21,op_load=22, op_loadAI=23, op_loadA0=24, op_cload=25, op_cloadAI=26, op_cloadA0=27,
	op_store=28, op_storeAI=29, op_storeA0=30,	op_cstore=31, op_cstoreAI=32, op_cstoreA0=33,op_i2i=34, op_c2c=35, op_c2i=36, 
	op_i2c=37,op_jump=38, op_jumpI=39,op_cbr=40,op_cmp_LT=41, op_cmp_LE=42, op_cmp_EQ=43, op_cmp_GE=44, op_cmp_GT=45, op_cmp_NE=46
 };
typedef enum ILOC_op ILOC_op_t;


/*
*
*	Rótulos de ILOC (LABEL)
*
*
*O rotulo sempre terá a regra de começar com 'L'
*Será utilizado para desvios na linguagem ILOC
*
*/
typedef char* ILOC_label_t;
/*
*
*	Registrador da linguagem ILOC
*
*
*O registrador precisa ter uma string para a identificação do nome
*Existem regra de todo o regitrador começar com 'r'
*/
typedef char* ILOC_register_t;


ILOC_register_t rarp = "rarp"; // registrador que aponta para a pilha
ILOC_register_t rbss = "rbss"; // registrador para dados globais
/*
* ILOC_operand
* um operando pode ser um literal, um registrado ou um valor da memória
* esse operando é usado para as operações da linguagem ILOC
*/
union ILOC_operand {
	int val;
	ILOC_register_t reg;
	ILOC_label_t label;
}ILOC_operand;

/*
* ILOC_operand_list_t
* uma lista da operandos para a realização das instruções da linguagem ILOC
*/
typedef struct ILOC_operand_list{
	union ILOC_operand op;
	struct ILOC_operand_list *next;
}ILOC_operand_list_t;



/*
* ILOC_instruction_t
* Uma instrução possui uma operação, uma lista de operandos fontes e um operando alvo para o resultado da operação
*/
typedef struct ILOC_instruction{
	ILOC_op_t operation;
	ILOC_operand_list_t *operand_src_list;
	ILOC_operand_list_t *operand_dst_list;
} ILOC_instruction_t;

/*
* ILOC_instruction_list
* Uma lista de instruções pode ser um programa em ILOC podendo conter uma label para representar a lista de instruções
*/
typedef struct ILOC_instruction_list{
	ILOC_instruction_t instruction;
	struct ILOC_instruction_list *next;
	ILOC_label_t label;
}ILOC_instruction_list_t;


/*
* createIlocOperandList
* entrada: void, saída: ILOC_instruction_list_t
* Objetivo criação de operandos ILOC para as instruções
*/
ILOC_operand_list_t* createIlocOperandList();

/*
* insertIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* insere um elemento na lista de operandos
*/
ILOC_operand_list_t* insertIlocOperandElement(union ILOC_operand op, ILOC_operand_list_t* operandList);

/*
* copyOperandList
* entrada: ILOC_operand_list_t saída: ILOC_operand_list_t
* copia a lista de operando para outra lista de operandos
* função utilizada para a lista de instruções
*/
ILOC_operand_list_t* copyOperandList(ILOC_operand_list_t* operandListSrc);

/*
* deleteIlocOperandElement
* entrada: ILOC_operand saída: ILOC_operand_list_t
* deleta elemento da lista de operandos
*/
ILOC_operand_list_t* deleteIlocOperandElement(union ILOC_operand op, ILOC_operand_list_t* operandList);

/*
* destroyIlocInstructionList
* entrada: void, saida: ILOC_operand_list_t	
* destroi a lista de operandos de ILOC por completo
*/
ILOC_operand_list_t* destroyIlocOperandList(ILOC_operand_list_t* operandList);

/*
* newInstruction
* entrada: ILOC_op_t, ILOC_operand, ILOC_operand, ILOC_operand, ILOC_operand
* criação de uma nova instrução
*/
ILOC_instruction_t * newInstruction(ILOC_op_t operation,union ILOC_operand operand_src1,union ILOC_operand operand_src2, union ILOC_operand operand_dst1,union ILOC_operand operand_dst2 ); 


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
ILOC_instruction_list_t* insertIlocInstructionsElement(ILOC_instruction_t* instruction, ILOC_label_t label, ILOC_instruction_list_t* instructionList);

/*
* deleteIlocInstructionsElement
* entrada: ILOC_instruction_t saída: ILOC_instruction_list_t
* deleta elemento da lista de instruções
*/
ILOC_instruction_list_t* deleteIlocInstructionsFirstElement(ILOC_instruction_list_t* instructionList);

/*
* destroyIlocInstructionList
* entrada: void, saida: ILOC_instruction_t	
* destroi a lista de instruções de ILOC por completo
*/
ILOC_instruction_list_t* destroyIlocInstructionList(ILOC_instruction_list_t* instructionList);

/*
*Função createRegister: void -> ILOC_register_t
*Cria uma registrador novo baseado nas regra de ILOC
*Retorna um novo Registrador 
*/
ILOC_register_t createRegister();

/*
* Função createLabel entrada: void -> ILOC_label_t:
* A função serve para criar uma label de acordo com as regras da linguagem iloc
* Retorna uma label nova
*/
ILOC_label_t createLabel();


/*
* função: code_ger
* Entrada: comp_tree_t Saída: void
* Gera código a partir da ast
*/
void code_ger(comp_tree_t** ast);
#endif