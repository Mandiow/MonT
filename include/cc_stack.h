#ifndef __CC_STACK_H
#define __CC_STACK_H
#include <math.h>
#include "cc_tree.h"
#include "cc_ast.h"
#include "cc_dict.h"
#include "cc_list.h"
#include "cc_error.h"



enum stack_type { data_item = 1 , block_item = 2 , param_item = 3};
typedef enum stack_type stack_flag;


typedef struct stack_item
{
	comp_dict_item_t* data;
	stack_flag flag;
	struct stack_item *prev;
}stack_item;


stack_item *main_stack;

void stack_initialize(stack_item* stack);
int stack_push(stack_item* stack, comp_dict_item_t* data, stack_flag flag);
void stack_pop(stack_item* stack);
int stack_isDeclared(stack_item* stack, comp_dict_item_t* data);
void stack_popBlock(stack_item* stack);
int typeInference(comp_tree_t* leftNode, comp_tree_t* rightNode);
int typeCoercion(comp_tree_t* leftNode, comp_tree_t* rightNode, int typeOfCommand);
void convertValue(int valueConversion, comp_tree_t* node);
#endif

