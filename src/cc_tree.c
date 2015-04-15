#include "cc_tree.h"


// Create a single node with the designed itemType and pointer to it's element in the table
comp_tree_t* createNode(int itemType, comp_dict_item_t* tableItem)
{
	comp_tree_t* newNode = (comp_tree_t*)malloc(sizeof(comp_tree_t));
	newNode->nodeChildList = (nodeList*)malloc(sizeof(nodeList)); 		// Initialise it's list of siblings as NULL
	newNode->nodeType = itemType;
	newNode->nodeFather = NULL;
}

// Inserts the desired node (newChild) as a sibling of the desired node (father)
void appendChildNode(comp_tree_t* father, comp_tree_t* newChild)
{
	comp_tree_t auxNode = father->nodeChildList->firstNode;
	nodeList auxNodeList = father->nodeChildList->nextNode;
	while (auxNode != NULL)
	{
		auxNode = auxNodeList->firstNode;
		if(auxNodeList != NULL)
			auxNodeList = auxNodeList->nextNode;
	}
	auxNode = newChild;
	auxNode->nodeFather = father;
}


/*
// Remove the desired node of the tree passed as argument
void removeNode(comp_tree_t* tree ,comp_tree_t* node)
{
	int removido = 0;
	comp_tree_t auxNode = tree;
	nodeList auxNodeList = tree->childNodeList;
	comp_tree_t acutalNode = tree;
	comp_tree_t oldNode = tree;
	nodeList auxNodeList2 = NULL;
	while(auxNode != node)
 	{
 		auxNode = auxNodeList->firstNode;
		if (auxNodeList != NULL)
			auxNodeList->auxNodeList->nextNode;
 		else
 		{
 			//oldNode = actualNode;
 			actualNode = actualNode->childNodeList->firstNode;
 			if (actualNode->childNodeList != NULL)
 				auxNodeList = actualNode->childNodeList
 			else
 			{
 				auxNodeList2 = oldNode->father->childNodeList;
 				while(auxNodeList2->firstNode != oldNode || auxNodeList2->nextNode != NULL)
 				{
 					auxNodeList2 = auxNodeList2->nextNode;
 				}
 				auxNodeList2 = auxNodelist2->nextNode;
 				if(auxNodeList2 != NULL)
 				{
 					auxNodeList = auxNodeList2;
 				}
 				else
 				{
 					actualNode = oldNode->father;
 					oldNode = oldNode->father;
 				}
 			}
 		}
 	}
}
*/

// Recursive function that removes the whole subtree (node) of a father passed as argument
void removeNode(comp_tree_t* father ,comp_tree_t* node)
{
	nodeList deletedNodeList = node->childNodeList;
	nodeList auxNodeList = father->childNodeList;
	while(auxNodeList!= NULL && auxNodeList!=node)
	{
		auxNodeList = auxNodeList->nextNode;
	}
	//Desalocar elemento e subárvore
	while(childNodeList != NULL)
	{
		removeNode(node, childNodeList->firstNode);
		free(childNodeList->firstNode);
		childNodeList->childNodeList->nextNode;
	}
	free(node->childNodeList);
}

void gv_create_initial_tree(comp_tree_t* tree)
{
	if (tree == NULL)
		return;
	nodeList auxNodeList = tree->childNodeList;
	switch(tree->itemType)
		case AST_IDENTIFICADOR:
			if(tree->tableItem != NULL)
				gv_declare(tree->itemType, tree, tree->tableItem->key);
			else
				gv_declare(tree->itemType, tree, "IDENTIFICADOR");
			break;
		case AST_LITERAL:
			if(tree->tableItem != NULL)
				gv_declare(tree->itemType, tree, tree->tableItem->key);
			else
				gv_declare(tree->itemType, tree, "LITERAL");
			break;
		case AST_FUNCAO:
			if(tree->tableItem != NULL)
				gv_declare(tree->itemType, tree, tree->tableItem->key);
			else
				gv_declare(tree->itemType, tree, "FUNCAO");
			break;
		default:
				gv_declare(tree->itemType, tree,  NULL);
			break;
	while(auxNodeList != NULL)
	{
		gv_create_subtree(tree, auxNodeList->firstNode);
		auxNodelist = auxNodeList->nextNode;
	}
	return;
}
void gv_create_subtree(comp_tree_t* father, comp_tree_t* node)
{
	nodeList auxNodeList = tree->childNodeList;
	switch(node->itemType)
	case AST_IDENTIFICADOR:
		if(node->tableItem != NULL)
			gv_declare(node->itemType, node, node->tableItem->key);
		else
			gv_declare(node->itemType, node, "IDENTIFICADOR");
		break;
	case AST_LITERAL:
		if(node->tableItem != NULL)
			gv_declare(node->itemType, node, node->tableItem->key);
		else
			gv_declare(node->itemType, node, "LITERAL");
		break;
	case AST_FUNCAO:
		if(node->tableItem != NULL)
			gv_declare(node->itemType, node, node->tableItem->key);
		else
			gv_declare(node->itemType, node, "FUNCAO");
		break;
	default:
			gv_declare(node->itemType, node,  NULL);
		break;
	gv_connect(father,node);

	while(auxNodeList != NULL)
	{
		gv_create_subtree(node, auxNodeList->firstNode);
		auxNodelist = auxNodeList->nextNode;
	}
	return;
}