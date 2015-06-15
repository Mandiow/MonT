#ifndef __CC_OPT_H
#define __CC_OPT_H

//Struct defines
typedef struct basicBlock{
	int id;
	int startLine;
	int endLine;
	intList* nextBlockList;
}BasicBlock;

typedef struct basicBlockList{
	basicBlock block;
	basicBlockList* nextBlock;
}basicBlockList;

typedef struct intList{
	int item;
	intList* next;
} intList;

typedef struct codeLineList{
	char* code;
	int isDominant; 				// 1 Means that he is dominant, otherwise he isn't
	codeLineList* nextLine;
}codeLineList;

//Declared globals
codeLineList* optCode; 
basicBlockList* basicBlocks; 		// Will be the list of basic blocks
intList* loopList;
intList* dominantList;

//Basic list operations
int appendCodeLine(char* codeLine, codeLineList* codeList);
int appendBlock(basicBlock block, basicBlockList* blockList);
int removeBlock(basicBlock block, basicBlockList* blockList);
int removeBlockID(int id, basicBlockList* blockList);
int appendInt(intList* intList, int item);
void sortIntList(intList* list);

//Useful things
int getCodeLineNumber(codeLineList* codeList);
void getCodeLines(char* originalCode);	//Saves in global optCode

//Optimization operations
void searchForDominants();			//Uses global optCode and global dominantList
int searchForBasicBlocks(); 		//Uses global optCode and global basicBlocks;
void removeBlockFootPrints(basicBlock* block); // Removes the block from the global lists, updating it's values (optCode, nexItemLines, etc);