#ifndef __CC_TREE_H
#define __CC_TREE_H
#include "cc_dict.h"
#include "cc_ast.h"

// TAMANHOS
#define INT_SIZE 4
#define FLOAT_SIZE 8
#define CHAR_SIZE 1
#define BOOL_SIZE 1

// COERÇÃO
#define COERCION_TO_INT 1
#define COERCION_TO_FLOAT 2
#define COERCION_TO_BOOL 5



typedef struct nodeList_t{
	struct comp_tree_t* firstNode;
	struct nodeList_t* nextNode;
}nodeList;

typedef struct comp_tree_t {
	char reg[100];
	char code[2048];				// As defined id cc_ast.h
	char labelTrue[100];
	char labelFalse[100];
	int nodeType;
	int iks_type;
	int ifThenElse;
	int IWANNAABOOLEAN;
	struct stack_item* callBackupStack;
	comp_dict_item_t* tableItem;	// The pointer in the Table to the item related in this node
    nodeList* childNodeList; 	// A list of this node siblings, (maximum varies depending on comp_tree_t.type)
    struct comp_tree_t* nodeFather;		// It's father in the ast
}compTree; 



compTree* syntaxTree;

compTree* createNode(int itemType, comp_dict_item_t* tableItem);
void *appendChildNode(compTree* t, compTree* newChild);
void removeNode(compTree* node);						
int searchTree (compTree* t, int data);
void gv_create_initial_tree(compTree* tree);
void __gv_create_subtree(compTree* father, compTree* node);
//void showTree(compTree* node);


#include "cc_stack.h"
#endif
