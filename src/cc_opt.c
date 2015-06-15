#include "cc_opt.h"
#include <string.h>
/** Basic list operations **/

//Return:
//-1 = if malloc fails
//0 if everything runs fine;
int appendCodeLine(char* codeLine, codeLineList* codeList)
{
	codeLineList codeListNewElem = (*codeLineList) malloc(sizeof(codeLineList));
	//Return -1 if malloc fails zzz
	codeLineList auxList;
	//Because reference can get nasty
	strcpy(codeLine,codeListNewElem->code);
	auxList = codeList;
	if(codeList == NULL)
	{
		codeList = codeListNewElem;
		return 0;
	}
	while(auxList->nextLine != NULL)
	{
		auxList = auxList->nextLine;
	}
	auxList->nextLine = codeListNewElem;
	codeListNewElem->nextLine = NULL;
	return 0;
}

//Return:
//-1 = if malloc fails
//0 if everything runs fine;
int appendBlock(basicBlock* block, basicBlockList* blockList)
{
	basicBlockList auxList;
	basicBlockList newBlockListElem = (*basicBlockList) malloc(sizeof(basicBlockList));
	//Return -1 if malloc fails zzz
	newBlockListElem->nextBlock = NULL;
	newBlockListElem->block = block;
	if(auxList == NULL)
	{
		blockList = newBlockListElem;
		return 0;
	}
	while(auxList->nextBlock != NULL)
	{
		auxList = auxList->nextBlock;
	}
	auxList->nextBlock = newBlockListElem;
	return 0;
}
int appendloopBlockList(int start, intList* interior, intList* end)
{
	loopBlockList auxList;
	loopBlockList newLoopBlockListElem = (*loopBlockList) malloc(sizeof(loopBlockList));
	//Return -1 if malloc fails zzz
	newLoopBlockListElem->nextLoop = NULL;
	newLoopBlockListElem->block = block;
	if(auxList == NULL)
	{
		blockList = newLoopBlockListElem;
		return 0;
	}
	while(auxList->nextLoop != NULL)
	{
		auxList = auxList->nextLoop;
	}
	auxList->nextLoop = newLoopBlockListElem;
	return 0;
}
// Returns: -1 = block not found on list
// 0 = Found and removed;
int removeBlock(basicBlock* block, basicBlockList* blockList)
{
	basicBlockList auxList;
	basicBlockList auxList2;
	auxList = blockList;
	if(blockList == NULL)
		return -1;
	while(auxList != NULL && auxList->block != block)
	{
		auxList = auxList->nextBlock;
		if(auxList->nextBlock != NULL && auxList->nextBlock->block == block )
			auxList2 = auxList;
	}
	if(auxList2 != NULL) //Found the block in the list
	{
		auxList2->nextBlock = auxList->nextBlock;
		//Free the whole block zzz
		return 0;
	}
	return -1;
}

//Same as above, but using the ID of the block
int removeBlockID(int id, basicBlockList* blockList)
{
	basicBlockList auxList;
	basicBlockList auxList2;
	auxList = blockList;
	if(blockList == NULL)
		return -1;
	while(auxList != NULL && auxList->block->id != id)
	{
		auxList = auxList->nextBlock;
		if(auxList->nextBlock != NULL && auxList->nextBlock->block->id == id )
			auxList2 = auxList;
	}
	if(auxList2 != NULL) //Found the block in the list
	{
		auxList2->nextBlock = auxList->nextBlock;
		//Free the whole block zzz
		return 0;
	}
	return -1;
}

//This function already have some optimization semantic on it;
//Should be set to -1 if it's not going to be used
int appendInt(intList* intList, int item)
{
	intList auxList;
	intList newIntElem;
	auxList = intList;

	newIntElem = (*intList) malloc(sizeof(intList));
	newIntElem->id = item;
	newIntElem->next = NULL;

	if(intList == NULL)
	{
		intList = newIntElem;
		return 0;
	}

	while(auxList->next != NULL)
		auxList = auxList->next;
	
	auxList->next = newIntElem;
	return 0;
}
intList* sortIntList(intList* head)
{
	intList* tmpPtr = head;
    intList* tmpNxt = head->next;
    int tmp;
    while(tmpNxt != NULL){
           while(tmpNxt != tmpPtr)
           {
                    if(tmpNxt->id < tmpPtr->id)
                    {
                            tmp = tmpPtr->id;
                            tmpPtr->id = tmpNxt->id;
                            tmpNxt->id = tmp;
                    }
                    tmpPtr = tmpPtr->next;
            }
            tmpPtr = head;
            tmpNxt = tmpNxt->next;
    }
    return tmpPtr ; // Place holder
}

/** Useful things **/
int getCodeLineNumber(codeLineList* codeList);
{
	int counter = 0;
	codeLineList auxList;
	auxList = codeList;
	while(auxList != NULL)
	{
		counter++;
		auxList = auxList->nextLine;
	}
	return counter;
}
//Parsing function that transforms original code string into a list of CodeList items that represent each line of the code
//Returns:
//-1 = Tried to call this function 2 times without setting the global to NULL; (Should not happen)
// 0 = global optCode now have every codeLine in the code;

int getCodeLines(char* originalCode);	//Saves in global optCode
{
	char* tempCode; 		
	char* lineString;
	//Because strtok can screw up the original string, so I need to pass a copy of the original one
	strcpy(tempCode,originalCode);
	if(optCode != NULL)
	{
		return -1; // Why would you do that
	}
	//Get the first token
	lineString = strtok(tempCode,"\n");
	appendCodeLine(lineString,optCode);
	//Walk through the other tokens
	while(lineString != NULL)
	{
		appendCodeLine(lineString,optCode);
		lineString = strtok(NULL,"\n");
	}
	return 0;
}

/** Optimization operations **/
void searchForLeaders();			//Uses global optCode and global dominantList
{
	codeLineList* auxCodeList;
	auxCodeList = optCode;
	//If he is the first element
	auxCodeList->optCode->isDominant = 1;
	//If there is a jump to this line of code or if this line is after a jump
	int search = 0;
	while(auxCodeList != NULL)
	{
		//If the instruction is a jump, conditional or not
		if (strstr(auxCodeList->code, "cbr") != NULL || strstr(auxCodeList->code, "jmp") != NULL || strstr(auxCodeList->code, "jmpI") != NULL) 
		{
		   	findJumpDestination(auxCodeList);
			if(auxCodeList->nextLine != NULL)
				auxCodeList->nextLine->isDominant = 1;
		}
		auxCodeList = auxCodeList->nextLine;
	}
	auxCodeList = optCode;
}

void findJumpDestination(codeLineList evaluatedLine)
{
	codeLineList* auxCodeList;
	auxCodeList = optCode;
	char* str;
	char* code;
	str = strtok(evaluatedLine," ");
	str = strtok(NULL," ");
	
	//Se estou procurando por uma label
	if(strstr(str,"L") != NULL)
	{
		while(auxCodeList != NULL)
		{
			code = strtok(auxCodeList, str);
			//If I found the codeline that have this label
			if(strstr(auxCodeList->code,code)!= NULL)
				auxCodeList->isDominant = 1;
			auxCodeList = auxCodeList->nextLine;
		}
	}
	//Se estou procurando por um valor de linha do código
	else
	{
		while(auxCodeList != NULL)
		{
			code = strtok(auxCodeList, str);
			//If I found the codeline that have this label
			if(strstr(auxCodeList->code,code)!= NULL)
				auxCodeList->isDominant = 1;
			auxCodeList = auxCodeList->nextLine;
		}
	}	
}

int searchForBasicBlocks(); 		//Uses global optCode and global basicBlocks
{
	//First code is the initial part of a basic block, so it should be the first step towards getting the full basicBlock List
	if(basicBlocks != NULL)
		return -1;
	basicBlockList blockList = (*basicBlockList) malloc(sizeof(basicBlockList));
	basicBlocks = blockList;

	//Mallocs the first block
	basicBlock* initialBlock = (*basicBlock) malloc(sizeof(basicBlock));
	initialBlock->id = 1;
	initialBlock->startLine = 1;
	initialBlock->endLine = 1;
	//Now we need to set the end line and the other possible initial blocks
	codeList* auxCodeList;
	auxCodeList = optCode;

	int counter = 1;
	int dominantCounter = 1;
	codeList* auxCodeList;
	auxCodeList = optCode->nextLine;
	while(auxCodeList != NULL)
	{
		if(auxCodeList->isDominant == 1)
		{
			if(dominantCounter == 1)
			{
				initialBlock->endLine = counter - 1;
				appendBlock(basicBlocks,initialBlock);
				//Mallocs the block
				basicBlock* block = (*basicBlock) malloc(sizeof(basicBlock));
				block->id = dominantCounter;
				block->startLine = counter;
			}
			else
			{
				block->endLine = counter;
				appendBlock(basicBlocks,block);
				//Mallocs the block
				basicBlock* block = (*basicBlock) malloc(sizeof(basicBlock));
				block->id = dominantCounter;
				block->startLine = counter;
			}
			dominantCounter++;
			//Now we need to set the end line and the other possible blocks
		}
		counter++;
	}
	linkBlocks();
	return 0;
}
//Uses globals, same as the function above, but only used to get the next possible jumps from each block;
void linkBlocks()
{
	basicBlockList blockAuxList;
	basicBlockList blockAuxList2;
	blockAuxList = basicBlocks;
	char* str;
	char* tempCode;
	int start;
	int value;
	int blockID;

	while(blockAuxList != NULL)
	{
		blockAuxList2 = basicBlocks;
		if (strstr(blockAuxList->code, "cbr") != NULL || strstr(auxCodeList->code, "jmp") != NULL || strstr(auxCodeList->code, "jmpI") != NULL)
		{
			//Found something that has a jump, now I need to search for the other part of the jump (label or adress)
			strcpy(tempCode,blockAuxList->block->code);
			str = strtok(tempCode->code, " ");
			str = strtok(NULL, " ");
			//Found a label, keep searching for it in the code
			if(strcmp(str,"L")!= NULL)
			{
				while(blockAuxList2 != NULL)
				{
					//FOUND YAAA
					if(strstr(blockAuxList2->block->code, str) != NULL)
						appendInt(blockAuxList->block->nextBlockList,blockAuxList2->block->id);
					blockAuxList2 = blockAuxList2->nextBlock;
				}
			}
			//Gotta search for the block that contains the line, if there is no register in the jump obviously
			if(strcmp(str,"r") == NULL)
			{
				value = atoi(str);
				while(blockAuxList2 != NULL)
				{
					if(start < value)
					{
						blockID = blockAuxList2->block->id;
						start = blockAuxList2->block->startLine;
					}
					else
						break;
					blockAuxList2 = blockAuxList2->nextBlock;
				}
				appendInt(blockAuxList->block->nextBlockList,blockAuxList2->block->id);	
			}
		}
	}
}

void searchForDominants()
{
/*
// dominator of the start node is the start itself
Dom(n0) = {n0}
// for all other nodes, set all nodes as the dominators
for each n in N - {n0}
 Dom(n) = N;
// iteratively eliminate nodes that are not dominators
while changes in any Dom(n)
	for each n in N - {n0}:
        Dom(n) = {n} union with intersection over Dom(p) for all p in pred(n)*/
}

/*//Search for loops in the basicBlockList
//Uses global basicBlocks and loopList;
void loopSearch(basicBlock* startBlock,basicBlock* actualBlock , loopBlockList* actualLoopList, basicBlockList* interiors)					
{
	if(actualBlock == NULL)
		actalBlock = startBlock;
	intList* auxIntList;
	auxIntList = actualBlock->nextBlockList;
	//If my actualBlock contains an exit to the first block of the possible loop, it is a loop and the loop is added to the loop list with it's interiors
	while(auxIntList != NULL)
	{
		if(auxIntList->item == startBlock->id)
		{
			
		}
		auxIntList = auxIntList->next;
	}
	//Now check it's sons in the list, going over them using this function recursively
}*/
//ok now the shady stuff comes in
void optimizeCode()
{
	//stuff that is shadier than Eminem goes here	
	Premissa P = {
		Movimentação de código para fora do laço L é válida se:
		1. O bloco B que contém s domina todas as saídas de L;
		2. Nenhum outro comando no laço atribui um valor à x;
		3. Todos os usos de x dentro de L são feitos na definição em S;
	}
	Para cada linha de código C pertencente à intersecção de (bloco B pertencente à basicBlocks) e (loopList)
		Se C aceita a premissa P
			Se existe um bloco B2 que tem como saida B.startBlock
				Realoca C para o final deste bloco B2;
			Se não
				//Caso onde estou tentando realocar uma linha de código de um bloco que está no início do programa, 
				//logo não tem nenhum bloco anterior a este no qual posso realocar o código C	
				Cria novo bloco básico B3 e realoca C para este bloco basico
				Faz com que este bloco básico seja o início da lista de blocos
}