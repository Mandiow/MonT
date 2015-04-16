#include "cc_tree.h"
#include <time.h>


// Create a single node with the designed nodeType and pointer to it's element in the table
comp_tree_t* createNode(int nodeType, comp_dict_item_t* tableItem)
{
	comp_tree_t* newNode = (comp_tree_t*)malloc(sizeof(comp_tree_t));
	newNode->childNodeList = (nodeList*)malloc(sizeof(nodeList)); 		// Initialise it's list of siblings as NULL
	newNode->nodeType = nodeType;
	newNode->tableItem = tableItem;
	newNode->nodeFather = NULL;
	
	return newNode;
}

// Inserts the desired node (newChild) as a sibling of the desired node (father)
void appendChildNode(comp_tree_t* father, comp_tree_t* newChild)
{
	if (newChild != NULL)
	{	
		comp_tree_t* auxNode = father->childNodeList->firstNode;
		nodeList* auxNodeList = father->childNodeList->nextNode;
		while (auxNode != NULL)
		{
			auxNode = auxNodeList->firstNode;
			if(auxNodeList != NULL)
				auxNodeList = auxNodeList->nextNode;
		}
		auxNode = newChild;
		auxNode->nodeFather = father;	
	}
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
} ^ THIS PROBABLY WILL BE USEFUL IF WE CAN'T GET IT TO WORK WITHOUT NEEDING THE FATHER POINTER
*/

// Recursive function that removes the whole subtree (node) of a father passed as argument
void removeNode(comp_tree_t* father ,comp_tree_t* node)
{
	nodeList* deletedNodeList = node->childNodeList;
	nodeList* auxNodeList = father->childNodeList;
	while(auxNodeList!= NULL && auxNodeList->firstNode!=node)
	{
		auxNodeList = auxNodeList->nextNode;
	}
	//Desalocar elemento e subárvore
	while(deletedNodeList != NULL)
	{
		removeNode(node, deletedNodeList->firstNode);
		free(deletedNodeList->firstNode);
		deletedNodeList->nextNode;
	}
	free(node->childNodeList);
}

void gv_create_initial_tree(comp_tree_t* tree)
{
	
	if (tree == NULL)
		return;
	nodeList* auxNodeList = tree->childNodeList;
	switch(tree->nodeType)
	{
		case AST_IDENTIFICADOR:
				gv_declare(tree->nodeType, tree, tree->tableItem->key);
			break;
		case AST_LITERAL:
				gv_declare(tree->nodeType, tree, tree->tableItem->key);
			break;
		case AST_FUNCAO:
				gv_declare(tree->nodeType, tree, tree->tableItem->key);
			break;
		default:
				gv_declare(tree->nodeType, tree,  NULL);
			break;
	}
}
void gv_create_subtree(comp_tree_t* father, comp_tree_t* node)
{
	if (node != NULL)
	{

		nodeList* auxNodeList = node->childNodeList->nextNode;
		printf("%p\n",auxNodeList );
		switch(node->nodeType)
		{
			case AST_IDENTIFICADOR:
					gv_declare(node->nodeType, node, node->tableItem->key);
				break;
			case AST_LITERAL:
					gv_declare(node->nodeType, node, node->tableItem->key);
				break;
			case AST_FUNCAO:
					gv_declare(node->nodeType, node, node->tableItem->key);
				break;
			default:
					gv_declare(node->nodeType, node,  NULL);
				break;
		}
		gv_connect(father,node);

		while(auxNodeList != NULL)
		{
			printf("você tem que passar por aqui, por favor, se não ta dando erro cacete\n");
			gv_create_subtree(node, auxNodeList->firstNode);
			auxNodeList = auxNodeList->nextNode;
		}	
	}
}