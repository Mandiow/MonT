#ifndef __CC_TREE_H
#define __CC_TREE_H
#include "cc_ast.h"
#include "cc_gv.h"
#include "cc_dict.h"

// TAMANHOS
#define INT_SIZE 4
#define FLOAT_SIZE 8
#define CHAR_SIZE 1
#define BOOL_SIZE 1

// COERÇÃO
#define COERCION_TO_INT 1
#define COERCION_TO_FLOAT 2
#define COERCION_TO_BOOL 5

typedef struct comp_tree_t comp_tree_t;
typedef struct nodeList_t nodeList;

struct nodeList_t{
	struct comp_tree_t* firstNode;
	struct nodeList_t* nextNode;
};

struct comp_tree_t {
	int nodeType;						// As defined id cc_ast.h
	comp_dict_item_t* tableItem;	// The pointer in the Table to the item related in this node
    nodeList* childNodeList; 	// A list of this node siblings, (maximum varies depending on comp_tree_t.type)
    comp_tree_t* nodeFather;		// It's father in the ast
}; 



comp_tree_t* syntaxTree;

comp_tree_t* createNode(int itemType, comp_dict_item_t* tableItem);
void *appendChildNode(comp_tree_t* t, comp_tree_t* newChild);
void removeNode(comp_tree_t* node);						
int searchTree (comp_tree_t* t, int data);
void gv_create_initial_tree(comp_tree_t* tree);
void __gv_create_subtree(comp_tree_t* father, comp_tree_t* node);
//void showTree(comp_tree_t* node);


#endif
