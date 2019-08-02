

#include <stdlib.h>

#include "rbTreex.h"


int main(int argc, char *argv[])
{
    stRbTreeRoot_t tree;
	stRbNode_t *nodePtr;

    rbTreexInit(&tree);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 10;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 11;
	rbTreexInsert(&tree, nodePtr);

	nodePtr = (stRbNode_t *)malloc(sizeof(*nodePtr));
	nodePtr->key = 13;
	rbTreexInsert(&tree, nodePtr);
    return 0;
}
