

#include "tree.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main (void)
{
	node_t *root = NULL;
	int idx;
	int array[] = {6,4,8,9,14,11,15,2,1};
	node_t *nodePtr = NULL;

	for (idx = 0;idx < sizeof(array)/sizeof(array[0]);idx++) {
		nodePtr=(node_t *)malloc(sizeof(node_t));
		nodePtr->key = array[idx];
		nodePtr->p = NULL;
		nodePtr->left = NULL;
		nodePtr->right = NULL;
		treeInsert(&root, nodePtr);
	}
	treeInorder(root);

	nodePtr = treeSearch(root, 6);
	printf("Key:%d\n", nodePtr->key);

	nodePtr = treeMinumum(root);
	printf("Key:%d\n", nodePtr->key);

	nodePtr = treeMaxmum(root);
	printf("Key:%d\n", nodePtr->key);

	node_t *basePtr = NULL;
#if 0
	for (idx = 0;idx < sizeof(array)/sizeof(array[0]);idx++) {
		basePtr = treeSearch(root, array[idx]);
		printf("Base Key:%d\n", basePtr->key);
		nodePtr = treePredecessor(basePtr);
		if (nodePtr){
			printf("Key:%d\n", nodePtr->key);
		}else{
			printf("none\n");
		}

		nodePtr = treeSuccessor(basePtr);
		if (nodePtr) {
			printf("Key:%d\n\n", nodePtr->key);
		}else{
			printf("none\n\n");
		}
	}
#endif

	basePtr = treeSearch(root, array[4]);
	printf("Base Key:%d\n", basePtr->key);
	treeDelete(&root, basePtr);
	treeInorder(root);


	return 0;
}

