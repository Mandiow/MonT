#ifndef __IKS_ILOC_H__
#define __IKS_ILOC_H__
#include "cc_ast.h"

/* 
INICIO PARCIOL DA ESTRUTURA DE DADOS PARA A LINGUAGEM ILOC
*/


/* 
Lista de operações possiveis na linguagem ILOC o enum serve para facilitar o acesso para a geração de código ILOC
*/

enum op {
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
typedef enum op op_t;


//registrador até agora foi pensado como um contador
typedef int count reg;
