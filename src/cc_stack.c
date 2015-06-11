#include "cc_stack.h"

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