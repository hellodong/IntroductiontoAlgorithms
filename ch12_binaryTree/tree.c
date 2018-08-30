

#include "tree.h"

#include <string.h>
#include <stdio.h>


int treeInsert(node_t **root, node_t *t)
{
	node_t *pre = NULL;
	node_t *x = *root;

	while(x != NULL) {
		pre = x;
		if (x->key > t->key) {
			x = x->left;
		}else{
			x = x->right;
		}
	}
	if (!pre) {
		*root = t;
		return 0;
	}

	if (pre->key > t->key) {
		pre->left = t;
	}else{
		pre->right = t;
	}
	t->p = pre;

	return 0;
}

void treeInorder(node_t *node)
{
	if (node) {
		treeInorder(node->left);
		printf("%d\n", node->key);
		treeInorder(node->right);
	}
}
