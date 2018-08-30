

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

#endif

