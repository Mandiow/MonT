#include "cc_stack.h"
#include "cc_error.h"
#include "cc_ast.h"
#include "cc_list.h"

#include <stdio.h>
#include <stdlib.h>


void stack_initialize(stack_item* stack)
{
	return;
}
void setTypeSize(comp_dict_item_t* data_item, cc_list_t* list, int typeDeclaration)
{
	switch(data_item->iks_type)
	{
		case IKS_INT:
			data_item->size = INT_SIZE;
			if(list!=NULL)
			{
				cc_list_t* aux_list;
				aux_list = list;
				while(aux_list != NULL)
				{
					data_item->size = aux_list->value * data_item->size;
					aux_list = aux_list->nextElem;
				}
			}
			break;
		case IKS_FLOAT:
			data_item->size = FLOAT_SIZE;
			break;
		case IKS_BOOL:
			data_item->size = BOOL_SIZE;
			break;
		case IKS_CHAR:
			data_item->size = CHAR_SIZE;
			break;
		case IKS_STRING:
			data_item->size = CHAR_SIZE * strlen(data_item->key)+1;
			break;
	}
	if(typeDeclaration == globalDeclaration)
	{
		data_item->offset = globalOffset;
		globalOffset += data_item->size;
	}
	else
	{
		data_item->offset = localOffset;
		localOffset += data_item->size;	
	}

}

int stack_push(stack_item **stack, comp_dict_item_t* data, stack_flag flag, int isDeclared)
{
	stack_item* new_item = (stack_item*)malloc(sizeof(stack_item));
	if(new_item == NULL)
		return MALLOC_ERROR;

	new_item->prev = NULL;
	if(flag >= data_item && isDeclared == 1)
		stackpush_isDeclared(*stack,data);
			

	if(*stack == NULL)
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
		if(flag == block_item)
		{
			new_item->prev = *stack;
			new_item->data = NULL;
			new_item->flag = flag;
			*stack = new_item;
			return IKS_SUCCESS;
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
}


void stack_pop(stack_item **stack)
{
	stack_item* item_aux;
	item_aux = *stack;
	*stack = item_aux->prev;
	free(item_aux);
	return;
}

int stackpush_isDeclared(stack_item* stack, comp_dict_item_t* data)
{
	if(stack == NULL || data == NULL)
		return -1;
	stack_item* aux_stack;
	aux_stack = stack;
	while(aux_stack != NULL && aux_stack->data != NULL && aux_stack->data->key != data->key && aux_stack->flag != block_item)
	{
		aux_stack = aux_stack->prev;
	}
	if(aux_stack == NULL || aux_stack->flag == block_item)
		return IKS_SUCCESS;
	exit(IKS_ERROR_DECLARED);
}

int stack_isDeclared(stack_item* stack, comp_dict_item_t* data, int typeExpected)
{
	//printStack(stack);
	if(stack == NULL || data == NULL)
		return -1;
	stack_item* aux_stack;
	aux_stack = stack;
	int found = 0;
	while(aux_stack != NULL && found == 0)
	{
		if(aux_stack->data != NULL)
			if(aux_stack->data->key == data->key)
				found = 1;
			else
				aux_stack = aux_stack->prev;
		else
			aux_stack = aux_stack->prev;
	}
	if(aux_stack == NULL || aux_stack->flag == block_item)
	{
		exit(IKS_ERROR_UNDECLARED);
	}

	if(aux_stack->data->nodeType != typeExpected)
	{
		switch(aux_stack->data->nodeType)
		{
			case AST_FUNCAO:
				if(typeExpected != AST_FUNCAO)
					exit(IKS_ERROR_FUNCTION);
				return IKS_SUCCESS;
			case AST_IDENTIFICADOR:
					exit(IKS_ERROR_VARIABLE);
			case AST_VETOR_INDEXADO:
					exit(IKS_ERROR_VECTOR);
			default: break;
		}	
	}

	return IKS_SUCCESS;
}

void stack_popBlock(stack_item **stack)
{
	if(*stack == NULL)
		return;
	
	while(*stack != NULL && (*stack)->flag <= block_item)
	{
		stack_pop(stack);
	}
	//printStack(*stack);
}

int returnCoercion(int returnType, comp_tree_t* rightElement)
{
	if (rightElement->tableItem != NULL)
		switch(returnType)
		{
			case IKS_INT:
				switch(rightElement->tableItem->iks_type)
				{
					case IKS_INT:
						//printf("CHEGUEI AQUI\n");
						return IKS_SUCCESS;
					case IKS_FLOAT:
						convertValue(COERCION_TO_INT,rightElement->tableItem);
						return IKS_SUCCESS;
					case IKS_BOOL:
						rightElement->tableItem->coercion = COERCION_TO_INT;
						convertValue(COERCION_TO_INT,rightElement->tableItem);
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);

				}
			case SIMBOLO_LITERAL_FLOAT:
				switch(rightElement->tableItem->iks_type)
				{
					case IKS_INT:
						rightElement->tableItem->coercion = COERCION_TO_FLOAT;
						convertValue(COERCION_TO_FLOAT,rightElement->tableItem);
						return IKS_SUCCESS;
					case IKS_FLOAT:
						return IKS_SUCCESS;
					case IKS_BOOL:
						rightElement->tableItem->coercion = COERCION_TO_FLOAT;
						convertValue(COERCION_TO_FLOAT,rightElement->tableItem);
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_BOOL:
				switch(rightElement->tableItem->iks_type)
				{
					case IKS_INT:
						convertValue(COERCION_TO_BOOL,rightElement->tableItem);
						return IKS_SUCCESS;
					case IKS_FLOAT:
						convertValue(COERCION_TO_BOOL,rightElement->tableItem);
						return IKS_SUCCESS;
					case IKS_BOOL:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_CHAR:
				switch(rightElement->tableItem->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
						exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_CHAR:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_STRING:
						exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_STRING:
				switch(rightElement->tableItem->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
					case SIMBOLO_LITERAL_CHAR:
						exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
						return IKS_SUCCESS;
				}
			default: return -1;
		}
	else
		switch(returnType)
		{
			case IKS_INT:
				switch(rightElement->iks_type)
				{
					case IKS_INT:
						//printf("CHEGUEI AQUI\n");
						return IKS_SUCCESS;
					case IKS_FLOAT:
						return IKS_SUCCESS;
					case IKS_BOOL:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);

				}
			case SIMBOLO_LITERAL_FLOAT:
				switch(rightElement->iks_type)
				{
					case IKS_INT:
						return IKS_SUCCESS;
					case IKS_FLOAT:
						return IKS_SUCCESS;
					case IKS_BOOL:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_BOOL:
				switch(rightElement->iks_type)
				{
					case IKS_INT:
						return IKS_SUCCESS;
					case IKS_FLOAT:
						return IKS_SUCCESS;
					case IKS_BOOL:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
								exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
								exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_CHAR:
				switch(rightElement->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
						exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_CHAR:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_STRING:
						exit(IKS_WRONG_PAR_RETURN);
				}
			case SIMBOLO_LITERAL_STRING:
				switch(rightElement->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
					case SIMBOLO_LITERAL_CHAR:
						exit(IKS_WRONG_PAR_RETURN);
					case SIMBOLO_LITERAL_STRING:
						return IKS_SUCCESS;
				}
			default: return -1;
		}
}

int typeInference(comp_tree_t* leftNode, comp_tree_t* rightNode)
{
	//printf("%d,%d\n",leftNode->tableItem->iks_type,rightNode->tableItem->iks_type );
	if(leftNode->tableItem == NULL || rightNode->tableItem == NULL)
	{	
		switch(leftNode->iks_type)
		{
			case IKS_INT:
				switch(rightNode->iks_type)
				{
					case IKS_INT:
						leftNode->nodeFather->iks_type = IKS_INT;
						return IKS_SUCCESS;
						/*father recieves IKS_INT*/
					case IKS_FLOAT:
						//leftNode->coercion = COERCION_TO_FLOAT;
						leftNode->nodeFather->iks_type = IKS_FLOAT;
						//convertValue(COERCION_TO_FLOAT,leftNode);
						return IKS_SUCCESS;
					case IKS_BOOL:
						//rightNode->coercion = COERCION_TO_INT;
						leftNode->nodeFather->iks_type = IKS_INT;
						//convertValue(COERCION_TO_INT,rightNode);
						return IKS_SUCCESS;
					case IKS_CHAR:
						exit(IKS_ERROR_CHAR_TO_X);
					case IKS_STRING:
						exit(IKS_ERROR_STRING_TO_X);
				}
			case SIMBOLO_LITERAL_FLOAT:
				switch(rightNode->iks_type)
				{
					case IKS_INT:
						//rightNode->coercion = COERCION_TO_FLOAT;
						leftNode->nodeFather->iks_type = IKS_FLOAT;
						//convertValue(COERCION_TO_FLOAT,rightNode);
						return IKS_SUCCESS;
						/*father recieves IKS_INT*/
					case IKS_FLOAT:
						leftNode->nodeFather->iks_type = IKS_FLOAT;
						return IKS_SUCCESS;
					case IKS_BOOL:
						//rightNode->coercion = COERCION_TO_FLOAT;
						leftNode->nodeFather->iks_type = IKS_FLOAT;
						//convertValue(COERCION_TO_FLOAT,rightNode);
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
						exit(IKS_ERROR_CHAR_TO_X);
					case SIMBOLO_LITERAL_STRING:
						exit(IKS_ERROR_STRING_TO_X);
				}
			case SIMBOLO_LITERAL_BOOL:
				switch(rightNode->iks_type)
				{
					case IKS_INT:
						//leftNode->coercion = COERCION_TO_INT;
						leftNode->nodeFather->iks_type = IKS_INT;
						//convertValue(COERCION_TO_INT,rightNode);
						return IKS_SUCCESS;
						/*father recieves IKS_INT*/
					case IKS_FLOAT:
						//leftNode->coercion = COERCION_TO_FLOAT;
						leftNode->nodeFather->iks_type = IKS_FLOAT;
						//convertValue(COERCION_TO_FLOAT,rightNode);
						return IKS_SUCCESS;
					case IKS_BOOL:
						leftNode->nodeFather->iks_type = IKS_BOOL;
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_CHAR:
						exit(IKS_ERROR_CHAR_TO_X);
					case SIMBOLO_LITERAL_STRING:
						exit(IKS_ERROR_STRING_TO_X);
				}
			case SIMBOLO_LITERAL_CHAR:
				switch(rightNode->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
						exit(IKS_ERROR_WRONG_TYPE);
					case SIMBOLO_LITERAL_CHAR:
						return IKS_SUCCESS;
					case SIMBOLO_LITERAL_STRING:
						exit(IKS_ERROR_STRING_TO_X);
				}
			case SIMBOLO_LITERAL_STRING:
				switch(rightNode->iks_type)
				{
					case IKS_INT:
					case IKS_FLOAT:
					case IKS_BOOL:
						exit(IKS_ERROR_WRONG_TYPE);
					case SIMBOLO_LITERAL_CHAR:
						exit(IKS_ERROR_CHAR_TO_X);
					case SIMBOLO_LITERAL_STRING:
						return IKS_SUCCESS;
				}
			default: break;
		}
	}
	else
	{
		switch(leftNode->tableItem->iks_type)
		{
		case IKS_INT:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					leftNode->nodeFather->iks_type = IKS_INT;
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					//leftNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,leftNode);
					return IKS_SUCCESS;
				case IKS_BOOL:
					//rightNode->coercion = COERCION_TO_INT;
					leftNode->nodeFather->iks_type = IKS_INT;
					//convertValue(COERCION_TO_INT,rightNode);
					return IKS_SUCCESS;
				case IKS_CHAR:
					exit(IKS_ERROR_CHAR_TO_X);
				case IKS_STRING:
					exit(IKS_ERROR_STRING_TO_X);
			}
		case SIMBOLO_LITERAL_FLOAT:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					//rightNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					leftNode->nodeFather->iks_type = IKS_FLOAT;
					return IKS_SUCCESS;
				case IKS_BOOL:
					//rightNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					exit(IKS_ERROR_CHAR_TO_X);
				case SIMBOLO_LITERAL_STRING:
					exit(IKS_ERROR_STRING_TO_X);
			}
		case SIMBOLO_LITERAL_BOOL:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
					//leftNode->coercion = COERCION_TO_INT;
					leftNode->nodeFather->iks_type = IKS_INT;
					//convertValue(COERCION_TO_INT,rightNode);
					return IKS_SUCCESS;
					/*father recieves IKS_INT*/
				case IKS_FLOAT:
					//leftNode->coercion = COERCION_TO_FLOAT;
					leftNode->nodeFather->iks_type = IKS_FLOAT;
					//convertValue(COERCION_TO_FLOAT,rightNode);
					return IKS_SUCCESS;
				case IKS_BOOL:
					leftNode->nodeFather->iks_type = IKS_BOOL;
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_CHAR:
					exit(IKS_ERROR_CHAR_TO_X);
				case SIMBOLO_LITERAL_STRING:
					exit(IKS_ERROR_STRING_TO_X);
			}
		case SIMBOLO_LITERAL_CHAR:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					exit(IKS_ERROR_WRONG_TYPE);
				case SIMBOLO_LITERAL_CHAR:
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_STRING:
					exit(IKS_ERROR_STRING_TO_X);
			}
		case SIMBOLO_LITERAL_STRING:
			switch(rightNode->tableItem->iks_type)
			{
				case IKS_INT:
				case IKS_FLOAT:
				case IKS_BOOL:
					exit(IKS_ERROR_WRONG_TYPE);
				case SIMBOLO_LITERAL_CHAR:
					exit(IKS_ERROR_CHAR_TO_X);
				case SIMBOLO_LITERAL_STRING:
					return IKS_SUCCESS;
			}
		default: break;	
		}
	}
}

int typeCoercion(comp_dict_item_t* leftElement, comp_dict_item_t* rightElement, int typeOfCommand) // typeOfCommand: 0 -> Att; 1 -> Return; 2 -> Input; 3 -> Output, 4->Function;
{
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
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: exit(IKS_WRONG_PAR_OUTPUT);
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_CHAR_TO_X);
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: return IKS_SUCCESS;
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_STRING_TO_X);
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
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: exit(IKS_WRONG_PAR_OUTPUT);
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_CHAR_TO_X);
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: return IKS_SUCCESS;
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_STRING_TO_X);
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
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: exit(IKS_WRONG_PAR_OUTPUT);
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_CHAR_TO_X);
						}
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: return IKS_SUCCESS;
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_STRING_TO_X);
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
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_WRONG_TYPE);
						}
				case SIMBOLO_LITERAL_CHAR:
					return IKS_SUCCESS;
				case SIMBOLO_LITERAL_STRING:
					switch(typeOfCommand)
						{
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: return IKS_SUCCESS;
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_STRING_TO_X);
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
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_WRONG_TYPE);
						}
				case SIMBOLO_LITERAL_CHAR:
					switch(typeOfCommand)
						{
							case 1: exit(IKS_WRONG_PAR_RETURN);
							case 2: exit(IKS_WRONG_PAR_INPUT);
							case 3: exit(IKS_WRONG_PAR_OUTPUT);
							case 4: exit(IKS_ERROR_WRONG_TYPE_ARGS);
							default : exit(IKS_ERROR_CHAR_TO_X);
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

void printStack(stack_item* stack)
{
	stack_item* aux_stack;
	aux_stack = stack;
	while(aux_stack != NULL)
	{
		if(aux_stack->data != NULL && aux_stack != NULL)
		{
			printf("Data Pointer: %p ",aux_stack->data);
			printf("; Key: %s ",aux_stack->data->key);
			printf("; Type %d ",aux_stack->data->tipo);
			printf("; IKS_TYPE: %d ",aux_stack->data->iks_type); 
			printf("; Flag %d\n ",aux_stack->flag);	
		}
		else
			printf("Data Pointer: %p ; Flag: %d\n",aux_stack->data, aux_stack->flag);	
		aux_stack = aux_stack->prev;
	}
}

int Function_Comparsion(int chamada,stack_item* stack, stack_item* call_stack)
{
	

	stack_item* aux_stack; 
	stack_item* aux_call_stack;

	stack_item* callParamStack;
	stack_item* mainParamStack;

	callParamStack = NULL;
	mainParamStack = NULL;

	aux_call_stack = call_stack;
	aux_stack = stack;

	while(aux_call_stack->flag != func_item)
	{
		if(aux_call_stack->flag == param_item)
		{
			stack_push(&callParamStack,aux_call_stack->data,param_item,0);
			//printf("CALL PARAM STACK POINTER: %p %s\n", callParamStack->data, aux_call_stack->data->key);
		}
		aux_call_stack = aux_call_stack->prev;
	}

	int Found = 0;
	while(aux_stack != NULL && Found == 0)
		{
			if(aux_stack->flag == param_item)
			{	
				stack_push(&mainParamStack,aux_stack->data,param_item,0);
			}
			if(aux_stack->data != NULL)
				if (aux_stack->data->key != aux_call_stack->data->key)
					aux_stack = aux_stack->prev;
				else Found = 1;
			else
				aux_stack = aux_stack->prev;
		}

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
		if (typeCoercion(mainParamStack->data,callParamStack->data,4) != IKS_SUCCESS)
		{
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

int getFunctionType(stack_item* stack, stack_item* call_stack)
{
	

	stack_item* aux_stack; 
	stack_item* aux_call_stack;

	aux_call_stack = call_stack;
	aux_stack = stack;

	while(aux_call_stack->flag != func_item)
	{
		aux_call_stack = aux_call_stack->prev;
	}
	int Found = 0;
	while(aux_stack != NULL && Found == 0)
		{
			if(aux_stack->data != NULL)
				if(aux_stack->data->key != aux_call_stack->data->key)
					aux_stack = aux_stack->prev;
				else Found = 1;
			else
				aux_stack = aux_stack->prev;
		}
	if (aux_stack->flag == func_item)
	{
		return aux_stack->data->iks_type;
	}
	else 
	{
		switch(aux_stack->data->nodeType)
			{
				case AST_IDENTIFICADOR:
					exit(IKS_ERROR_VARIABLE);
				case AST_VETOR_INDEXADO:
					exit(IKS_ERROR_VECTOR);
			}
	}
}