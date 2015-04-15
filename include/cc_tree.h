#include "cc_dict.h"
#include "cc_ast.h"
#include "cc_gv.h"

typedef struct nodeList_t{
	struct comp_tree_t* firstNode;
	struct nodeList_t* nextNode;
}nodeList;

struct comp_tree_t {
	int nodeType;						// As defined id cc_ast.h
	comp_dict_item_t* tableItem;	// The pointer in the Table to the item related in this node
    nodeList* childNodeList; 	// A list of this node siblings, (maximum varies depending on comp_tree_t.type)
    comp_tree_t* nodeFather;		// It's father in the ast
}; 

comp_tree_t* syntaxTree;

comp_tree_t* createNode(int itemType, comp_dict_item_t* tableItem);
void appendChildNode(comp_tree_t* t, comp_tree_t* newChild);
void removeNode (comp_tree_t* node);								
int searchTree (comp_tree_t* t, int data);
//void showTree(comp_tree_t* node);