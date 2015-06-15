#ifndef __CC_SEM_H
#define __CC_SEM_H
#include "cc_stack.h"
#include "cc_dict.h"
#include "cc_tree.h"




int Function_Comparsion(int chamada,stack_item* stack, stack_item* call_stack, compTree* ast);
int returnCoercion(int returnType, compTree* rightElement);
int typeInference(compTree* leftNode, compTree* rightNode);
int typeCoercion(comp_dict_item_t* leftElement, comp_dict_item_t* rightElement, int typeOfCommand);


#endif