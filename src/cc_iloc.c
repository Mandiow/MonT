#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cc_iloc.h"


int labelControl=0; 	// numero do próxima label, será utilizado para a criação de labels
int registerControl=0; 	// numero do próximo registrador, será utilizado para a criação de registradores
char* labelMain;
int ilocCodeLineNumber=0;
int activationReg=0;
ILOC_register_t rarp = "rarp"; // registrador que aponta para a pilha
ILOC_register_t rbss = "rbss"; // registrador para dados globais

char* createRegister()
{
	char string[311];
	sprintf(string, "r%d", registerControl); 
	registerControl++;
	return strdup(string);

}

char* createLabel()
{
	char string[311];
	sprintf(string, "L%d", labelControl); 
	labelControl++;
	return strdup(string);
}

char* basicCodeGeneration(ILOC_op_t operation, char* firstOperant, char* secondOperant, char* thirdOperant)
{
	char generatedCode[2048];
	switch(operation)
	{
		case op_add:
			sprintf(generatedCode, "add %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_sub:
			sprintf(generatedCode, "sub %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_mult:
			sprintf(generatedCode, "mult %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_div:
			sprintf(generatedCode, "div %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_addI:
			sprintf(generatedCode, "addi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_subI:
			sprintf(generatedCode, "subi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_rsubI:
			sprintf(generatedCode, "rsubi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_multI:
			sprintf(generatedCode, "multi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_rdivI:
			sprintf(generatedCode, "rdivi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_divI:
			sprintf(generatedCode, "divi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_lshift:
			sprintf(generatedCode, "lshift %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_rshift:
			sprintf(generatedCode, "rshift %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_and:
			sprintf(generatedCode, "and %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_or:
			sprintf(generatedCode, "or %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_xor:
			sprintf(generatedCode, "xor %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_loadA0:
			sprintf(generatedCode, "loadA0 %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cloadA0:
			sprintf(generatedCode, "cloadA0 %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cmp_LT:
			sprintf(generatedCode, "cmp_LT %s,%s => %s\n",firstOperant,secondOperant,thirdOperant); 
			break;
		case op_cmp_LE:
			sprintf(generatedCode, "cmp_LE %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cmp_EQ:
			sprintf(generatedCode, "cmp_EQ %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cmp_GE:
			sprintf(generatedCode, "com_GE %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cmp_GT:
			sprintf(generatedCode, "cmp_GT %s,%s => %s\n",firstOperant,secondOperant,thirdOperant); 
			break;
		case op_cmp_NE:
			sprintf(generatedCode, "cmp_NE %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_lshiftI:
			sprintf(generatedCode, "lshifti %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_rshiftI:
			sprintf(generatedCode, "rshifti %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_andI:
			sprintf(generatedCode, "andi %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_orI:
			sprintf(generatedCode, "ori %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_xorI:
			sprintf(generatedCode, "xori %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_loadAI:
			sprintf(generatedCode, "loadai %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cloadAI:
			sprintf(generatedCode, "clodai %s,%s => %s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_load:
			sprintf(generatedCode, "load %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_cload:
			sprintf(generatedCode, "cload %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_store:
			sprintf(generatedCode, "store %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_cstore:
			sprintf(generatedCode, "cstore %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_i2i:
			sprintf(generatedCode, "i2i %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_c2c:
			sprintf(generatedCode, "c2c %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_c2i:
			sprintf(generatedCode, "c2i %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_i2c:
			sprintf(generatedCode, "i2c %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_loadI:
			sprintf(generatedCode, "loadi %s => %s\n",firstOperant,thirdOperant);
			break;
		case op_storeAI:
			sprintf(generatedCode, "storeai %s => %s,%s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cstoreAI:
			sprintf(generatedCode, "cstoreai %s => %s,%s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_storeA0:
			sprintf(generatedCode, "storea0 %s => %s,%s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_cstoreA0:
			sprintf(generatedCode, "cstorea0 %s => %s,%s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_jumpI:
			sprintf(generatedCode, "jumpi %s\n",firstOperant);
			break;
		case op_jump:
			sprintf(generatedCode, "jump %s\n",firstOperant);
			break;
		case op_cbr:
			sprintf(generatedCode, "cbr %s => %s,%s\n",firstOperant,secondOperant,thirdOperant);
			break;
		case op_label:
			sprintf(generatedCode, "%s:\n",firstOperant);
			break;
		case op_halt:
			sprintf(generatedCode, "halt\n");
			break;
		default: 
			return NULL;
	}
	return strdup(generatedCode);
}

char* astCodeGenerate(compTree* ast)
{
	if(ast == NULL)
		return "ERRRROOOOOO - FAUSTAO";
	nodeList* auxNodeList;
	auxNodeList = ast->childNodeList;
	char createdCode[1024];
	char tempCode[1024];
	char label[100];
	char *regParam;
	strcpy(createdCode,"");
	strcpy(tempCode,"");

	switch(ast->nodeType)
	{
		case AST_PROGRAMA:
			ilocCodeLineNumber+=5;
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(tempCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			strcat(createdCode,basicCodeGeneration(op_loadI,integerToString(ilocCodeLineNumber),NULL,"rbss"));
			strcat(createdCode,basicCodeGeneration(op_loadI,"2048",NULL,"sp"));
			strcat(createdCode,basicCodeGeneration(op_loadI,"2048",NULL,"fp"));
			strcat(createdCode,basicCodeGeneration(op_jumpI,labelMain,NULL,NULL));
			strcat(createdCode,tempCode);
			strcat(createdCode,basicCodeGeneration(op_halt,NULL,NULL,NULL));
			//printf("ILOC CODE LINE NUMBER: %d\n",ilocCodeLineNumber );
			break;

		case AST_FUNCAO:
			if(strcmp(ast->tableItem->key,"main") == 0)
			{
				labelMain = createLabel();
				strcpy(createdCode,basicCodeGeneration(op_label,labelMain,NULL,NULL));
				strcat(createdCode,basicCodeGeneration(op_addI,"sp",integerToString(ast->frame),"sp"));
				ilocCodeLineNumber++;
				activationReg = 1;

			}
			else 
			{
				int functionOffset = 12;
				functionOffset += ast->frame;
				ast->tableItem->functionLabel = createLabel();
				strcpy(createdCode,basicCodeGeneration(op_label,ast->tableItem->functionLabel,NULL,NULL));
				strcat(createdCode,basicCodeGeneration(op_i2i,"sp",NULL,"fp"));
				ilocCodeLineNumber++;
				strcat(createdCode,basicCodeGeneration(op_addI,"sp",integerToString(functionOffset),"sp"));
				ilocCodeLineNumber++;
				activationReg = 0;
			}
			// Parâmetros vão ficar voando pra sempre zzzz(Gabriel)
			// Mas na 6ª eles voltam, relaxa ;3(Caiã)
			// ELES VOLTARAM!!!!!! e me zoaram hard (Gabriel)
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			break;
		case AST_CHAMADA_DE_FUNCAO:
			regParam = createRegister();
			strcpy(ast->reg,regParam);
			//Executa o código das expressões da chamada de função

			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			
			//Processar os parâmetros que estão salvos no nodo da AST.
			int paramOffset = 8;
			stack_item* aux_stack;
			aux_stack = ast->callBackupStack;
			int paramCounter = 0;
			int paramCounter2= 0;
			int lastparam = 0;
			while(aux_stack != NULL)
			{
				auxNodeList = ast->childNodeList;
				switch(aux_stack->data->iks_type)
				{
					case IKS_INT:
						paramOffset += 4;
						lastparam = 4;
						paramCounter++;
						break;
					case IKS_FLOAT:
						paramOffset += 8;
						lastparam = 8;
						paramCounter++;
						break;
					case IKS_CHAR:
						paramOffset += 1;
						lastparam = 1;
						paramCounter++;
						break;
					case IKS_STRING:
						paramOffset += 1; //Não sei como implementar isso na verdade
						lastparam = 1;
						paramCounter++;
						break;
					case IKS_BOOL:
						paramOffset += 1;
						lastparam = 1;
						paramCounter++;
						break;
				}
				while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
				{
					if(auxNodeList->firstNode->IWANNAABOOLEAN == 1)
					{
						paramCounter2++;
					}
					if(paramCounter2 == paramCounter)
						{
							break;
						}
					if(auxNodeList->nextNode == NULL )
						auxNodeList = auxNodeList->firstNode->childNodeList;
					else auxNodeList = auxNodeList->nextNode;
				}
				strcat(createdCode,basicCodeGeneration(op_storeAI,auxNodeList->firstNode->reg, "sp",integerToString(paramOffset))); //reg: registrador que armazena o resultado da expressao
				ilocCodeLineNumber++;
				aux_stack = aux_stack->prev;
				paramCounter2 = 0;
			}
			strcat(createdCode,basicCodeGeneration(op_storeAI,integerToString(ilocCodeLineNumber+5),"sp","0"));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_storeAI,"sp","sp","4"));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_storeAI,"fp","sp","8"));
			ilocCodeLineNumber++;

			//Jump para função
			strcat(createdCode,basicCodeGeneration(op_jumpI,ast->childNodeList->firstNode->tableItem->functionLabel,NULL,NULL));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_loadAI,"sp",integerToString(paramOffset+lastparam),ast->reg));

			
			break;
		case AST_RETURN:
			regParam = createRegister();
			char* fp = createRegister();
			char* sp = createRegister();
			
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			int returnOffset=12;
			returnOffset += ast->frame;

			strcat(createdCode,basicCodeGeneration(op_load,ast->childNodeList->firstNode->reg,NULL,regParam));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_storeAI,regParam,"fp",integerToString(returnOffset)));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_loadAI,"fp","0",regParam));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_loadAI,"fp","4",sp));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_loadAI,"fp","8",fp));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_store,fp,NULL,"fp"));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_store,sp,NULL,"sp"));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_jump,regParam,NULL,NULL));
			ilocCodeLineNumber++;

			break;
			
		case AST_IF_ELSE:
			//If statment
			strcpy(ast->reg,createRegister());
			if (ast->ifThenElse == 1)
				strcpy(label,createLabel());
			//Statement
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));			
			auxNodeList = auxNodeList->nextNode;

			//CBR VAI ENTRAR AQUI EM ALGUM MOMENTO MÁGICO.
			strcat(createdCode,basicCodeGeneration(op_cbr,ast->childNodeList->firstNode->reg,ast->labelTrue,ast->labelFalse));
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelTrue,NULL,NULL));
			//EU FALEI!
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			auxNodeList = auxNodeList->nextNode;

			if (ast->ifThenElse == 1)
			{
				//else exists
				strcat(createdCode,basicCodeGeneration(op_jumpI,label,NULL,NULL));
				strcat(createdCode,basicCodeGeneration(op_label,ast->labelFalse,NULL,NULL));
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				strcat(createdCode,basicCodeGeneration(op_label,label,NULL,NULL));
				ilocCodeLineNumber+=2;
			}
			else
			{
				strcat(createdCode,basicCodeGeneration(op_label,ast->labelFalse,NULL,NULL));
				ilocCodeLineNumber++;
			}

			break;

		case AST_DO_WHILE:
			strcpy(ast->reg,createRegister());
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelTrue,NULL,NULL));
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			auxNodeList = auxNodeList->nextNode;
			//Statement
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));			
			strcat(createdCode,basicCodeGeneration(op_cbr,auxNodeList->firstNode->reg,ast->labelTrue,ast->labelFalse));
			ilocCodeLineNumber++;
			auxNodeList = auxNodeList->nextNode;
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelFalse,NULL,NULL));

			break;

		case AST_WHILE_DO:
			//Statement
			strcpy(ast->reg,createRegister());
			strcpy(label,createLabel());
			strcat(createdCode,basicCodeGeneration(op_label,label,NULL,NULL));
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));			
			auxNodeList = auxNodeList->nextNode;
			strcat(createdCode,basicCodeGeneration(op_cbr,ast->childNodeList->firstNode->reg,ast->labelTrue,ast->labelFalse));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelTrue,NULL,NULL));
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			auxNodeList = auxNodeList->nextNode;
			strcat(createdCode,basicCodeGeneration(op_jumpI,label,NULL,NULL));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelFalse,NULL,NULL));


			break;


		// Casos de input e output só precisa concatenar o código gerado pelos nodos filhos da árvore
		case AST_INPUT:
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			break;

		case AST_OUTPUT:
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			break;

		case AST_ATRIBUICAO:
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			auxNodeList = auxNodeList->nextNode;
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			auxNodeList = auxNodeList->nextNode;
			if(ast->tableItem->scopeType == 0) // IF THE DOESNT HAVE A LOCAL SCOPE
			{

				strcat(createdCode,basicCodeGeneration(op_storeAI,ast->childNodeList->nextNode->firstNode->reg,"bss",integerToString(ast->tableItem->offset)));
				ilocCodeLineNumber++;
			}	
			
			if(ast->tableItem->scopeType == 1 && activationReg == 0)
			{
				strcat(createdCode,basicCodeGeneration(op_storeAI,ast->childNodeList->nextNode->firstNode->reg,"fp",integerToString(ast->tableItem->offset+12)));
				ilocCodeLineNumber++;	
			}
			if(ast->tableItem->scopeType == 1 && activationReg == 1)
			{
				strcat(createdCode,basicCodeGeneration(op_storeAI,ast->childNodeList->nextNode->firstNode->reg,"fp",integerToString(ast->tableItem->offset)));
				ilocCodeLineNumber++;	
			}
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			
			break;


		case AST_BLOCO:
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			break;

		case AST_IDENTIFICADOR:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->tableItem->scopeType == 0) // IF THE DOESNT HAVE A LOCAL SCOPE
			{

				strcat(createdCode,basicCodeGeneration(op_loadAI,"bss",integerToString(ast->tableItem->offset),ast->reg));
				ilocCodeLineNumber++;
			}	
			
			if(ast->tableItem->scopeType == 1 && activationReg == 0)
			{
				strcat(createdCode,basicCodeGeneration(op_loadAI,"fp",integerToString(ast->tableItem->offset+12),ast->reg));
				ilocCodeLineNumber++;	
			}
			if(ast->tableItem->scopeType == 1 && activationReg == 1)
			{
				strcat(createdCode,basicCodeGeneration(op_loadAI,"fp",integerToString(ast->tableItem->offset),ast->reg));
				ilocCodeLineNumber++;	
			}
			break;

		case AST_LITERAL:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			strcat(createdCode,basicCodeGeneration(op_loadI,ast->tableItem->key,NULL,ast->reg));
			ilocCodeLineNumber++;
			break;

		case AST_ARIM_SOMA:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->reg != NULL)
			{
				strcat(createdCode,basicCodeGeneration(op_add,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
				ilocCodeLineNumber++;
			}
			else
			{
				strcat(createdCode,basicCodeGeneration(op_addI,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->reg));
				ilocCodeLineNumber++;
			}
			break;

		case AST_ARIM_SUBTRACAO:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
			{	
				if(ast->childNodeList->nextNode->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
				{	
					if (ast->childNodeList->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
					{	
						strcat(createdCode,basicCodeGeneration(op_sub,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
						ilocCodeLineNumber++;
					}
					else
					{
						strcat(createdCode,basicCodeGeneration(op_rsubI,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->childNodeList->firstNode->reg,ast->reg));
						ilocCodeLineNumber++;
					}
				}
				else
				{
					strcat(createdCode,basicCodeGeneration(op_subI,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->reg));
					ilocCodeLineNumber++;
				}
			}
			else
			{
				strcat(createdCode,basicCodeGeneration(op_sub,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
				ilocCodeLineNumber++;
			}

			break;

		case AST_ARIM_MULTIPLICACAO:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->reg != NULL)
			{
				strcat(createdCode,basicCodeGeneration(op_mult,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
				ilocCodeLineNumber++;
			}
			else
			{ 
				strcat(createdCode,basicCodeGeneration(op_multI,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->reg));
				ilocCodeLineNumber++;
			}
			

			break;

		case AST_ARIM_DIVISAO:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				if(ast->childNodeList->nextNode->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
				{	
					if (ast->childNodeList->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
					{
						strcat(createdCode,basicCodeGeneration(op_div,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
						ilocCodeLineNumber++;
					}
					else 
					{
						strcat(createdCode,basicCodeGeneration(op_rdivI,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->childNodeList->firstNode->reg,ast->reg));
						ilocCodeLineNumber++;
					}
				}
				else 
				{
					strcat(createdCode,basicCodeGeneration(op_divI,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->tableItem->key,ast->reg));
					ilocCodeLineNumber++;
				}

			break;

		case AST_ARIM_INVERSAO:
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			break;

		case AST_LOGICO_E:
			strcpy(ast->reg,createRegister());
			
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			
			strcat(createdCode,astCodeGenerate(auxNodeList->nextNode->firstNode));
			strcat(createdCode,basicCodeGeneration(op_cbr,auxNodeList->firstNode->reg,ast->labelTrue,ast->labelFalse));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelTrue,NULL,NULL));

			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				if(ast->childNodeList->nextNode->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
				{
					strcat(createdCode,basicCodeGeneration(op_and,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
				}
				else 
				{
					strcat(createdCode,basicCodeGeneration(op_andI,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->tableItem->key,ast->reg));
					ilocCodeLineNumber++;
				}
			else 
			{
				strcat(createdCode,basicCodeGeneration(op_and,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->reg,ast->reg));
				ilocCodeLineNumber++;
			}
			
			break;

		case AST_LOGICO_OU:
			strcpy(ast->reg,createRegister());
			strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
			strcat(createdCode,astCodeGenerate(auxNodeList->nextNode->firstNode));
			strcat(createdCode,basicCodeGeneration(op_cbr,auxNodeList->firstNode->reg,ast->labelTrue,ast->labelFalse));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_label,ast->labelFalse,NULL,NULL));
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				if(ast->childNodeList->nextNode->firstNode->tableItem->tipo == SIMBOLO_IDENTIFICADOR)
				{
					strcat(createdCode,basicCodeGeneration(op_or,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
				}
				else 
				{
					strcat(createdCode,basicCodeGeneration(op_orI,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->tableItem->key,ast->reg));
					ilocCodeLineNumber++;
				}
			else 
			{
				strcat(createdCode,basicCodeGeneration(op_or,auxNodeList->firstNode->reg,auxNodeList->nextNode->firstNode->reg,ast->reg));
				ilocCodeLineNumber++;
			}
			
				
			

			break;

		case AST_LOGICO_COMP_IGUAL:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_EQ,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					
				}

			break;

		case AST_LOGICO_COMP_DIF:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_NE,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
					
				}

			break;

		case AST_LOGICO_COMP_LE:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_LE,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
					
				}

			break;

		case AST_LOGICO_COMP_GE:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_GE,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
					
				}

			break;

		case AST_LOGICO_COMP_L:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_LT,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
					
				}
			break;

		case AST_LOGICO_COMP_G:
			strcpy(ast->reg,createRegister());
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}
			if(ast->childNodeList->nextNode->firstNode->tableItem != NULL)
				{
					strcat(createdCode,basicCodeGeneration(op_cmp_GT,ast->childNodeList->firstNode->reg,ast->childNodeList->nextNode->firstNode->reg,ast->reg));
					ilocCodeLineNumber++;
					
				}

			break;

		case AST_LOGICO_COMP_NEGACAO:
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			break;

		case AST_VETOR_INDEXADO:
			// Cria registrador para retorno da posição à ser acessada
			strcpy(ast->reg,createRegister());
			//Executa e cria código recursivamente para os nodos filhos
			auxNodeList = auxNodeList->nextNode;
			while(auxNodeList != NULL && auxNodeList->firstNode != NULL)
			{
				strcat(createdCode,astCodeGenerate(auxNodeList->firstNode));
				auxNodeList = auxNodeList->nextNode;
			}

			//Verifica recursivamente se o ultimo elemento de algum filho (3o elemento para expressão, 2o para literal existe)
			int counter = 0;
			int update = 0;
			int limitDimensions;
			int control;
			char lastRegister[100];
			char tempRegister[100];
			nodeList* auxNodeListVectors;
			compTree* auxNode;
			cc_list_t* dimList;
			dimList = ast->childNodeList->firstNode->tableItem->array;
			auxNode = ast->childNodeList->nextNode->firstNode;
			auxNodeListVectors = ast->childNodeList->nextNode;
			limitDimensions = dimList->dimensions;
			control = limitDimensions;

			// Verifica primariamente se só tenho uma dimensão, caso só tenha uma dimensão não é necessário entrar no while.
			if (limitDimensions == 1)
			{
				limitDimensions--;
				strcpy(lastRegister,createRegister());
				strcat(createdCode,basicCodeGeneration(op_load,auxNode->reg,NULL,lastRegister));
				ilocCodeLineNumber++;
			}

			while(limitDimensions > 0 && auxNodeListVectors != NULL)
			{
				// Soma o contador a cada nodo filho do [] do vetor indexado
				counter++;
				if(auxNode->nodeType >= AST_ARIM_SOMA && auxNode->nodeType <= AST_LOGICO_COMP_NEGACAO)
				{
					if(counter == 2)
					{
						strcpy(tempRegister,createRegister());
						strcat(createdCode,basicCodeGeneration(op_load,auxNode->reg,NULL,tempRegister));
						ilocCodeLineNumber++;
						if(limitDimensions < control)
						{
							strcat(createdCode,basicCodeGeneration(op_multI,lastRegister,integerToString(dimList->value),tempRegister));
							ilocCodeLineNumber++;
							strcat(createdCode,basicCodeGeneration(op_add,tempRegister,lastRegister,tempRegister));
							ilocCodeLineNumber++;
						}
						dimList = dimList->nextElem;
						
						strcpy(lastRegister,tempRegister);
						counter = 0;
						limitDimensions--;
						auxNodeListVectors = auxNode->childNodeList;
						auxNode = auxNodeListVectors->firstNode;
						update = 1;

					}
				}
				if(auxNode->nodeType == AST_IDENTIFICADOR)
				{
					if(counter == 1)
					{
						
						strcpy(tempRegister,createRegister());
						strcat(createdCode,basicCodeGeneration(op_load,auxNode->reg,NULL,tempRegister));
						ilocCodeLineNumber++;
						if(limitDimensions < control)
						{
							strcat(createdCode,basicCodeGeneration(op_multI,lastRegister,integerToString(dimList->value),tempRegister));
							ilocCodeLineNumber++;
							strcat(createdCode,basicCodeGeneration(op_add,tempRegister,lastRegister,tempRegister));
							ilocCodeLineNumber++;
						}
						dimList = dimList->nextElem;

						strcpy(lastRegister,tempRegister);
						counter = 0;
						limitDimensions--;
						auxNodeListVectors = auxNode->childNodeList;
						auxNode = auxNodeListVectors->firstNode;
						update = 1;
					}
				}
				if(auxNode->nodeType == AST_LITERAL)
				{
					if(counter == 1)
					{
						strcpy(tempRegister,createRegister());
						strcat(createdCode,basicCodeGeneration(op_load,auxNode->reg,NULL,tempRegister));
						ilocCodeLineNumber++;
						if(limitDimensions < control)
						{
							strcat(createdCode,basicCodeGeneration(op_multI,lastRegister,integerToString(dimList->value),tempRegister));
							ilocCodeLineNumber++;
							strcat(createdCode,basicCodeGeneration(op_add,tempRegister,lastRegister,tempRegister));
							ilocCodeLineNumber++;
						}
						dimList = dimList->nextElem;

						limitDimensions = limitDimensions - 1;
						strcpy(lastRegister,tempRegister);
						counter = 0;
						auxNodeListVectors = auxNode->childNodeList;
						auxNode = auxNodeListVectors->firstNode;
						update = 1;
					}
				}
				if (update == 0)
					auxNodeListVectors = auxNodeListVectors->nextNode;
				update = 0;
			}
			strcat(createdCode,basicCodeGeneration(op_multI,lastRegister,integerToString(ast->childNodeList->firstNode->tableItem->iks_type),lastRegister));
			ilocCodeLineNumber++;
			char test[100];

			strcat(createdCode,basicCodeGeneration(op_addI,lastRegister,integerToString(ast->childNodeList->firstNode->tableItem->offset),lastRegister));
			ilocCodeLineNumber++;
			strcat(createdCode,basicCodeGeneration(op_load,lastRegister,NULL,ast->reg));
			ilocCodeLineNumber++;
			sprintf(test,"\n");
			strcat(createdCode,test);
			break;

		

		default:
			fprintf(stderr,"Erro na geracao de codigo! (Tipo do Nodo da AST não identificado)\n");
			break;
	}
	return strdup(createdCode);
}

char* integerToString(int x)
{
	char stringTemp[100];
	sprintf(stringTemp,"%d",x);
	return strdup(stringTemp);
}

void shortCircuit(compTree* ast, char* lTrue, char* lFalse)
{
	if(ast == NULL)
		return;
	nodeList* auxNodeList;
	char labelTemp[100];
	auxNodeList = ast->childNodeList;
	switch(ast->nodeType)
	{
		case AST_IF_ELSE:
		case AST_WHILE_DO:
		case AST_DO_WHILE:
			strcpy(ast->labelTrue,createLabel());
			strcpy(ast->labelFalse,createLabel());
			break;
		case AST_LOGICO_E:
			strcpy(labelTemp,createLabel());
			strcpy(ast->labelTrue,labelTemp);
			strcpy(ast->labelFalse,lFalse);
			break;
		case AST_LOGICO_OU:
			strcpy(labelTemp,createLabel());
			strcpy(ast->labelFalse,labelTemp);
			strcpy(ast->labelTrue,lTrue);
			break;
	}
	while(auxNodeList != NULL)
	{
		shortCircuit(auxNodeList->firstNode,ast->labelTrue,ast->labelFalse);
		auxNodeList = auxNodeList->nextNode;
	}
}
