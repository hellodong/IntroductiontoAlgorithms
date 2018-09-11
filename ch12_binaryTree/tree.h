

#ifndef _TREE_H_
#define _TREE_H_


typedef struct{
	int value;	
}StaData_t;

typedef struct _node
{
	StaData_t sta;
	int key;
	struct _node *p;
	struct _node *left;
	struct _node *right;	
}node_t;


int treeInsert(node_t **root, node_t *t);

void treeInorder(node_t *node);

node_t *treeSearch(node_t *root, int key);

node_t *treeMinumum(node_t *root);

node_t *treeMaxmum(node_t *root);

node_t *treePredecessor(node_t *root);

node_t *treeSuccessor(node_t *root);

void treeDelete(node_t **root, node_t *t);

#endif

