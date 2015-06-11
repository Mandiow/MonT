#include "cc_semantic.h"
int returnCoercion(int returnType, compTree* rightElement)
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

int typeInference(compTree* leftNode, compTree* rightNode)
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

int Function_Comparsion(int chamada,stack_item* stack, stack_item* call_stack, compTree* ast)
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
	stack_item* aux_stack123;
	aux_stack123 = mainParamStack;
	while(callParamStack != NULL && mainParamStack != NULL)
	{
			if (typeCoercion(mainParamStack->data,callParamStack->data,4) != IKS_SUCCESS)
			{
				exit(IKS_ERROR_WRONG_TYPE_ARGS);
			}
		mainParamStack = mainParamStack->prev;
		callParamStack = callParamStack->prev;
	}
	ast->callBackupStack = aux_stack123;

	return IKS_SUCCESS;

}