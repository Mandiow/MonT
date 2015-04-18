#include "cc_tree.h"
#include <time.h>


// Create a single node with the designed nodeType and pointer to it's element in the table
comp_tree_t* createNode(int nodeType, comp_dict_item_t* tableItem)
{
	comp_tree_t* newNode = (comp_tree_t*)malloc(sizeof(comp_tree_t));
	newNode->childNodeList = (nodeList*)malloc(sizeof(nodeList)); 		// Initialise it's list of siblings as NULL
	//newNode->childNodeList->nextNode = (nodeList*)malloc(sizeof(nodeList));
	newNode->childNodeList->firstNode = NULL;
	newNode->nodeType = nodeType;
	newNode->tableItem = tableItem;
	newNode->nodeFather = NULL;
	
	return newNode;
}

// Inserts the desired node (newChild) as a sibling of the desired node (father)
void *appendChildNode(comp_tree_t* father, comp_tree_t* newChild)
{
	int count = 1;
	if (newChild != NULL)
	{	
		nodeList *auxNodeList;
		auxNodeList = father->childNodeList;
		newChild->nodeFather = father;
		
		if(auxNodeList->firstNode == NULL)
		{
			auxNodeList->firstNode = newChild;
			auxNodeList->nextNode = NULL;

		}
		else
		{
			while (auxNodeList->nextNode != NULL)
			{
				auxNodeList = auxNodeList->nextNode;
				//printf("auxNodeList: %p\n", auxNodeList);
				count++;
			}
			auxNodeList->nextNode = (nodeList*)malloc(sizeof(nodeList));
			auxNodeList->nextNode->firstNode = newChild;
			auxNodeList->nextNode->nextNode = NULL;
			//printf("PAI: %p FILHO: %p\n",father,father->childNodeList->nextNode->nextNode);
		}	
		// while(auxNodeList != NULL)
		// {
		// 	if(auxNode != NULL && auxNode->childNodeList != NULL && auxNode->childNodeList->firstNode != NULL)
		// 	{
		// 		__gv_create_subtree(node, auxNode->childNodeList->firstNode);
		// 		// auxNode = auxNode->childNodeList->firstNode;
		// 	}
		// 	auxNodeList = auxNodeList->nextNode;
		// 	if(auxNodeList != NULL && auxNode->childNodeList->firstNode != NULL)
		// 		auxNode = auxNodeList->firstNode;
		// }
		
		
		// printf("NEWCHILD: %p\n", newChild);
	 //    printf("AUXNODE: %p\n", auxNode);
		// printf("PAI: %p FILHO: %p\n",father,father->childNodeList->firstNode);
		//printf("%d\n",count );
	}
}

// Recursive function that removes the whole subtree (node) of a father passed as argument
/*void removeNode(comp_tree_t* father ,comp_tree_t* node)
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
}*/
void removeNode(comp_tree_t* node)
{
	if(node != NULL)
	{
		nodeList* deletedNodeList = node->childNodeList;
		//Desalocar elemento e subárvore
		while(deletedNodeList != NULL)
		{
			removeNode(deletedNodeList->firstNode);
			free(deletedNodeList->firstNode);
			deletedNodeList = deletedNodeList->nextNode;
		}
		free(node->childNodeList);
	}
}
void gv_create_initial_tree(comp_tree_t* tree)
{
	
	if (tree == NULL)
		return;
	comp_tree_t* auxNode;
	auxNode = tree;
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
			
	
		if(auxNode->childNodeList->firstNode != NULL)
			__gv_create_subtree(tree, auxNode->childNodeList->firstNode);
		

}
void __gv_create_subtree(comp_tree_t* father, comp_tree_t* node)
{
	if (node != NULL)
	{
		switch(node->nodeType)
		{
			case AST_IDENTIFICADOR:
				if(node->tableItem != NULL)
					gv_declare(node->nodeType, node, node->tableItem->key);
				else
					gv_declare(node->nodeType, node, "IDENTIFICADOR");
				break;
			case AST_LITERAL:
				if(node->tableItem != NULL)
					gv_declare(node->nodeType, node, node->tableItem->key);
				else
					gv_declare(node->nodeType, node, "LITERAL");
				break;
			case AST_FUNCAO:
					gv_declare(node->nodeType, node, node->tableItem->key);
				break;
			default:
					gv_declare(node->nodeType, node,  NULL);
				break;
		}
		gv_connect(father,node);

		comp_tree_t* auxNode;
		auxNode = node;
		nodeList* auxNodeList;
		auxNodeList = node->childNodeList;

		while(auxNodeList != NULL)
		{
			if(auxNodeList->firstNode != NULL)
			{
				printf("%d\n", auxNodeList->firstNode->nodeType);
				__gv_create_subtree(node,auxNodeList->firstNode);		
			}
			auxNodeList = auxNodeList->nextNode;
		}

		// while(auxNodeList != NULL)
		// {
		// 	if(auxNode != NULL)
		// 	{
		// 		__gv_create_subtree(node, auxNode->childNodeList->firstNode);
		// 		 //auxNode = auxNode->childNodeList->firstNode;
		// 	}
		// 	if(auxNode->childNodeList->nextNode != NULL)
		// 		auxNode = auxNode->childNodeList->nextNode->firstNode;
		// 	else auxNodeList = auxNodeList->nextNode;
		// }

		
		

	}
}

void showTree(comp_tree_t* tree)
{
	if(tree->tableItem != NULL)
		printf("%s\n",tree->tableItem->key);	
	else
		printf("$\n");
	nodeList* auxNodeList;
	auxNodeList = tree->childNodeList;
	while(auxNodeList!= NULL)
	{
		if(auxNodeList->firstNode != NULL && auxNodeList->firstNode->tableItem != NULL)
			printf("%p ",auxNodeList->firstNode);	
		else	
			printf("# ");
		auxNodeList = auxNodeList->nextNode;
		if(auxNodeList != NULL)
		showTree(auxNodeList->firstNode);
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