#ifndef __IKS_ILOC_H__
#define __IKS_ILOC_H__
#include "cc_ast.h"

/* 
*Lista de operações possiveis na linguagem ILOC o enum serve para facilitar o acesso para a geração de código ILOC
*/
enum ILOC_op {
	op_nop = 0

	op_add=1, 
	op_sub=2, 
	op_mult=3, 
	op_div=4,

	op_addI=5,
	op_subI=6,
	op_rsubI=7 
	op_multI=8, 
	op_divI=9, 
	op_rdivI=10,
		
	op_lshift=11, 
	op_lshiftI=12,
	op_rshift=13,
	op_rshifI=14,

	op_and=15, 
	op_andI=16, 
	op_or=17, 
	op_orI=18, 
	op_xor=19, 
	op_xorI=20, 	

	op_loadI=21,
	
	op_load=22, 
	op_loadAI=23, 
	op_loadA0=24, 
		
	op_cload=25, 
	op_cloadAI=26, 
	op_cloadA0=27,
	
	op_store=28, 
	op_storeAI=29, 
	op_storeA0=30,	
	
	op_cstore=31, 
	op_cstoreAI=32, 
	op_cstoreA0=33,	

	op_i2i=34, 
	op_c2c=35, 
	op_c2i=36, 
	op_i2c=37,

	op_jump=38, 
	op_jumpI=39,

	op_cbr=40,

	op_cmp_LT=41, 
	op_cmp_LE=42, 
	op_cmp_EQ=43, 
	op_cmp_GE=44, 
	op_cmp_GT=45, 
	op_cmp_NE=46, 
 };
typedef enum ILOC_op ILOC_op_t;


/*
*
*	Registrador da linguagem ILOC
*
*
*O registrador precisa ter uma string para a identificação do nome, uma vez que existam regra para identificar se o registrador está escrito no padrão de ILOC
*O registrador possui um valor inteiro que será usado para o dado que será armazenado pela linguagem
*/
typedef struct ILOC_reg{
	int data;
	char *name;
} ILOC_register_t;

/*
*Função createRegister: int , char* -> ILOC_register_t*
*Verifica se o registrador está escrito de maneira correta em ILOC e adiciona o dado no registrador
*Retorna um Registrador novo com o dado atualizado.
*/
ILOC_register_t* createRegister(int data, char *name);


/*
*
*	Rótulos de ILOC (LABEL)
*
*
*O nome do rótulo tem a como objetivo a verificação se na criação do rótulo está correto a sintaxe do rótulo quando está criado.
*Outro objetivo do nome é uma chave para o endereço da sequencia de instruções a qual o rótulo foi inicializado.
*Pos nada mais é do que a posição onde o é iniciada a sequencia de instruções a qual esta label referencia.
*/
typedef struct label{
	char *name;
	int position;
} ILOC_label_t;

/*
* Função createLabel char* , int -> ILOC_label_t*
* A função serve para verificar se a label já existe no programa e se ela possui as regras de label na linguagem.
* Retorna a label caso ela seja criada com sucesso e retorna NULL em caso de erro ou a label já exista.
*/
ILOC_label_t*  createLabel(char* label_name, int position);

/*
*Uma Cédula de Memória em ILOC
*Implementação de uma cédula memória para utilização das instruções 
*A cédula de memória contem a posição dela na memória em si, e o valor do dado que ela armazena.
*/
/*typedef struct ILOC_memory_cell{
	int position;
	int data;
} ILOC_memory_cell_t;
*/
/*
*Lista de instruções vão ser necessárias para cada nodo da ast para geração de código, vai ser usado no cc_list
*Será necessário também uma lista de operandos de entrada e de saída para a geração das instruções.
*/
/*
* função: code_ger
* Entrada: comp_tree_t Saída: void
* Gera código a partir da ast
*/
void code_ger(comp_tree_t** ast);