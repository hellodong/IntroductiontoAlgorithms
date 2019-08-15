

#include <stdio.h>
#include <stdlib.h>

#include "rbTreex.h"


int main(int argc, char *argv[])
{
    stRbTreeRoot_t tree;
	stRbNode_t *nodePtr;
	int key;

    rbTreexInit(&tree);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 17;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 14;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 13;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 11;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 10;
	rbTreexInsert(&tree, nodePtr);

    rbTreexInorderWalk(&tree);

	key = 11;
	nodePtr = rbTreexSearch(&tree, key);
	if (nodePtr != tree.nil){
		printf("Found Key:%d\r\n", nodePtr->key);
	}else{
		printf("Can't found Key\r\n");
	}



    return 0;
}
