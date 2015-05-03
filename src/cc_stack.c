#include "cc_stack.h"
#include "cc_error.h"
#include "cc_ast.h"

#include <stdio.h>
#include <stdlib.h>


void stack_initialize(stack_item* stack)
{
	return;
}


int stack_push(stack_item **stack, comp_dict_item_t* data, stack_flag flag)
{
	stack_item* new_item = (stack_item*)malloc(sizeof(stack_item));

	if(new_item == NULL)
		return MALLOC_ERROR;
	new_item->prev = NULL;
	if(flag >= data_item)
		if(stack_isDeclared(*stack,data) == IKS_SUCCESS)
			exit(IKS_ERROR_DECLARED);
	
	if(stack == NULL)
	{
		
		if(flag == block_item)
		{
			new_item->data = NULL;
			new_item->flag = flag;
			*stack = new_item;
			return IKS_SUCCESS;
		}
		else
		{
			new_item->data = data;
			new_item->flag = flag;
			*stack = new_item;
			return IKS_SUCCESS;
			
		}
	}
	else
	{
		new_item->prev = *stack;
		new_item->flag = flag;
		new_item->data = data;
		*stack = new_item;
		return IKS_SUCCESS;
	}
}


void stack_pop(stack_item* stack)
{
	stack_item* item_aux;
	item_aux = stack;
	stack = stack->prev;
	free(item_aux->data);
	free(item_aux);
	return;
}

int stack_isDeclared(stack_item* stack, comp_dict_item_t* data)
{
	if(stack == NULL || data == NULL)
		return -1;
	stack_item* aux_stack;
	aux_stack = stack;
	while(aux_stack != NULL && aux_stack->data != NULL && aux_stack->data->key != data->key)
	{
		aux_stack = aux_stack->prev;
	}
	printf("erro1\n");
	if(aux_stack == NULL)
		return IKS_ERROR_UNDECLARED;

	if(aux_stack->data->nodeType != data->nodeType)
	{
		switch(aux_stack->data->nodeType)
		{
			case AST_FUNCAO:
				if(data->nodeType != AST_CHAMADA_DE_FUNCAO)
					return IKS_ERROR_FUNCTION;
				return IKS_SUCCESS;
			case AST_IDENTIFICADOR:
					return IKS_ERROR_VARIABLE ;
			case AST_VETOR_INDEXADO:
					return IKS_ERROR_VECTOR;
			default: break;
		}	
	}

	return IKS_SUCCESS;
}


void stack_popBlock(stack_item* stack)
{
	if(stack == NULL)
		return;
	while(stack->flag != block_item)
	{
		stack_pop(stack);
	}
	stack_pop(stack);
	while(stack->flag == param_item)
	{
		stack_pop(stack);
	}
}

int typeInference(comp_tree_t* leftNode, comp_tree_t* rightNode)
{
	switch(leftNode->tableItem->iks_type)
	{
		case IKS_INT:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					leftNode->nodeFather->tableItem->iks_type = IKS_INT;
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					//leftNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->tableItem->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,leftNode);
					return IKS_SUCCESS;
				case IKS_BOOL:
					//rightNode->coercion = COERCION_TO_INT;
					leftNode->nodeFather->tableItem->iks_type = IKS_INT;
					//convertValue(COERCION_TO_INT,rightNode);
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					return IKS_ERROR_CHAR_TO_X;
				case SIMBOLO_LITERAL_STRING:
					return IKS_ERROR_STRING_TO_X;
			}
		case SIMBOLO_LITERAL_FLOAT:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					//rightNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->tableItem->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					leftNode->nodeFather->tableItem->iks_type = IKS_FLOAT;
					return IKS_SUCCESS;
				case IKS_BOOL:
					//rightNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->tableItem->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					return IKS_ERROR_CHAR_TO_X;
				case SIMBOLO_LITERAL_STRING:
					return IKS_ERROR_STRING_TO_X;
			}
		case SIMBOLO_LITERAL_BOOL:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					//leftNode->coercion = COERCION_TO_INT;
					leftNode->nodeFather->tableItem->iks_type = IKS_INT;
					//convertValue(COERCION_TO_INT,rightNode);
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					//leftNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->tableItem->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
				case IKS_BOOL:
					leftNode->nodeFather->tableItem->iks_type = IKS_BOOL;
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					return IKS_ERROR_CHAR_TO_X;
				case SIMBOLO_LITERAL_STRING:
					return IKS_ERROR_STRING_TO_X;
			}
		case SIMBOLO_LITERAL_CHAR:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					return IKS_ERROR_WRONG_TYPE;
				case SIMBOLO_LITERAL_CHAR:
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_STRING:
					return IKS_ERROR_STRING_TO_X;
			}
		case SIMBOLO_LITERAL_STRING:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					return IKS_ERROR_WRONG_TYPE;
				case SIMBOLO_LITERAL_CHAR:
					return IKS_ERROR_CHAR_TO_X;
				case SIMBOLO_LITERAL_STRING:
					return IKS_SUCCESS;
			}
		default: break;
	}
}

int typeCoercion(comp_dict_item_t* leftElement, comp_dict_item_t* rightElement, int typeOfCommand) // typeOfCommand: 0 -> Att; 1 -> Return; 2 -> Input; 3 -> Output;
{
	printf("LEFTELEMENT: %s %d, RIGHTELEMENT: %s %d\n",leftElement->key, leftElement->iks_type, rightElement->key, rightElement->iks_type);
	//FALTA CORRIGIR O OUTPUT, JÁ QUE TÁ TÃO AMBIGUO QUANTO A MINHA CARA.
	switch(leftElement->iks_type)
	{
		case IKS_INT:
			switch(rightElement->iks_type)
			{
				case IKS_INT:
					//printf("CHEGUEI AQUI\n");
					return IKS_SUCCESS;
				case IKS_FLOAT:
					leftElement->coercion = COERCION_TO_FLOAT;
					convertValue(COERCION_TO_FLOAT,leftElement);
					return IKS_SUCCESS;
				case IKS_BOOL:
					rightElement->coercion = COERCION_TO_INT;
					convertValue(COERCION_TO_INT,rightElement);
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;

							default : return IKS_ERROR_CHAR_TO_X;
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_STRING_TO_X;
						}
			}
		case SIMBOLO_LITERAL_FLOAT:
			switch(rightElement->iks_type)
			{
				case IKS_INT:
					rightElement->coercion = COERCION_TO_FLOAT;
					convertValue(COERCION_TO_FLOAT,rightElement);
					return IKS_SUCCESS;
				case IKS_FLOAT:
					return IKS_SUCCESS;
				case IKS_BOOL:
					rightElement->coercion = COERCION_TO_FLOAT;
					convertValue(COERCION_TO_FLOAT,rightElement);
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_CHAR_TO_X;
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_STRING_TO_X;
						}
			}
		case SIMBOLO_LITERAL_BOOL:
			switch(rightElement->iks_type)
			{
				case IKS_INT:
					leftElement->coercion = COERCION_TO_INT;
					convertValue(COERCION_TO_INT,rightElement);
					return IKS_SUCCESS;
				case IKS_FLOAT:
					leftElement->coercion = COERCION_TO_FLOAT;
					convertValue(COERCION_TO_FLOAT,rightElement);
					return IKS_SUCCESS;
				case IKS_BOOL:
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_CHAR_TO_X;
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_STRING_TO_X;
						}
			}
		case SIMBOLO_LITERAL_CHAR:
			switch(rightElement->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_WRONG_TYPE;
						}
				case SIMBOLO_LITERAL_CHAR:
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_STRING_TO_X;
						}
			}
		case SIMBOLO_LITERAL_STRING:
			switch(rightElement->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_WRONG_TYPE;
						}
				case SIMBOLO_LITERAL_CHAR:
					switch(typeOfCommand)
						{
							case 1: return IKS_WRONG_PAR_RETURN;
							case 2: return IKS_WRONG_PAR_INPUT;
							
							default : return IKS_ERROR_CHAR_TO_X;
						}
				case SIMBOLO_LITERAL_STRING:
					return IKS_SUCCESS;
			}
		default: return -1;
	}
}

void convertValue(int valueConversion, comp_dict_item_t* node)
{
	if(valueConversion == COERCION_TO_FLOAT)
	{
		if (node->iks_type == IKS_INT)
		{
			node->iks_type = IKS_FLOAT;
			node->tipo = SIMBOLO_LITERAL_FLOAT;
			node->token.floating_point = (float)node->token.integer;
			return;
		}
		if (node->iks_type == IKS_BOOL)
		{
			node->iks_type = IKS_FLOAT;
			node->tipo = SIMBOLO_LITERAL_FLOAT;
			node->token.floating_point = (float)node->token.boolean;
			return;
		}
	}
	else if(valueConversion == COERCION_TO_INT)
	{
		if (node->iks_type == IKS_BOOL)
		{
			node->iks_type = COERCION_TO_INT;
			node->tipo = SIMBOLO_LITERAL_INT;
			node->token.integer = (int)node->token.boolean;
			return;
		}

		if (node->iks_type == IKS_FLOAT)
		{
			node->iks_type = COERCION_TO_INT;
			node->tipo = SIMBOLO_LITERAL_INT;
			node->token.integer = (int)(node->token.floating_point);
			return;
		}
	}
	else if(valueConversion == COERCION_TO_BOOL)
	{
		if (node->iks_type == IKS_INT)
		{
			node->iks_type = COERCION_TO_BOOL;
			node->tipo = SIMBOLO_LITERAL_BOOL;
			node->token.boolean = (int)node->token.integer;
			return;
		}

		if (node->iks_type == IKS_FLOAT)
		{
			node->iks_type = COERCION_TO_BOOL;
			node->tipo = SIMBOLO_LITERAL_BOOL;
			if(node->token.floating_point >= 0.5)
				node->token.boolean = 1;
			else
				node->token.boolean = 0;
			return;
		}
		
	}
}


int Function_Comparsion(int chamada,stack_item* stack, stack_item* call_stack)
{
	

	stack_item* aux_stack; 
	stack_item* aux_call_stack;

	stack_item* callParamStack;
	stack_item* mainParamStack;

	aux_call_stack = call_stack;
	aux_stack = stack;

	printf("flag do aux_call_stack: %d\n", aux_call_stack->flag);



	while(aux_call_stack->flag != func_item)
	{
		printf("entrei no while\n");
		if(aux_call_stack->flag == param_item)
		{
			stack_push(&callParamStack,aux_call_stack->data,3);
		}
		aux_call_stack = aux_call_stack->prev;
	}
	printf("oie");
	printf("callParamStack->data->key: %s\n",callParamStack->data->key);

	while(aux_stack->data->key != aux_call_stack->data->key)
		{
			if(aux_call_stack->flag == param_item)
			{	
				printf("ESTOU PUSHANDO\n");
				stack_push(&mainParamStack,aux_stack->data,3);
			}

			aux_stack = aux_stack->prev;
		}
	printf("mainParamStack->data->key: %s\n",mainParamStack->data->key);

	if(aux_stack->flag != func_item)
		{
			switch(aux_stack->data->nodeType)
			{
				case AST_IDENTIFICADOR:
					exit(IKS_ERROR_VARIABLE);
				case AST_VETOR_INDEXADO:
					exit(IKS_ERROR_VECTOR);
			}
		}
	if(aux_stack->data->param<chamada)
	{
		exit(IKS_ERROR_EXCESS_ARGS);
	}
	if(aux_stack->data->param>chamada)
	{
		exit(IKS_ERROR_MISSING_ARGS);
	}

	while(callParamStack != NULL)
	{
		if (typeCoercion(mainParamStack->data,callParamStack->data,0) != IKS_SUCCESS)
		{
			//printf("ERRO ENTRE COERÇÃO DE %d, %d\n",aux_stack->data->iks_type, aux_call_stack->data->iks_type);
			exit(IKS_ERROR_WRONG_TYPE_ARGS);
		}
		mainParamStack = mainParamStack->prev;
		callParamStack = callParamStack->prev;
	}


	return IKS_SUCCESS;

}


void paramcounter(stack_item** stack, int param)
{
	stack_item* aux_call_stack;
	aux_call_stack = *stack;

	while(aux_call_stack->flag != func_item)
	{
		aux_call_stack = aux_call_stack->prev;
	}
	aux_call_stack->data->param = param;
}