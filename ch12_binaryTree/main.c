

#include "tree.h"

#include <string.h>
#include <stdlib.h>



int main (void)
{
	node_t *root = NULL;
	int idx;
	int array[] = {6,4,8,9,2,1};
	node_t *nodePtr = NULL;

	for (idx = 0;idx < 6;idx++)
	{
		nodePtr=(node_t *)malloc(sizeof(node_t));
		nodePtr->key = array[idx];
		nodePtr->p = NULL;
		nodePtr->left = NULL;
		nodePtr->right = NULL;
		treeInsert(&root, nodePtr);
	}
	treeInorder(root);
	return 0;
}
