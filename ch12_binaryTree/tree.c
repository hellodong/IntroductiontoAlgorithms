

#include "tree.h"

#include <stdio.h>
#include <stdlib.h>


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

node_t *treeSearch(node_t *root, int key)
{
	node_t *node=root;
	while(node && node->key != key) {
		if (node->key < key) {
			node = node->right;
		}else{
			node = node->left;
		}
	}
	
	return node;
}

node_t *treeMinumum(node_t *root)
{
	node_t *node = root;
	while(node->left)
	{
		node=node->left;
	}
	return node;
}

node_t *treeMaxmum(node_t *root)
{
	node_t *node = root;
	while(node->right)
	{
		node=node->right;
	}
	return node;
}

node_t *treePredecessor(node_t *root)
{
	node_t *node = root, *pre = NULL;
	if (root->left) {
		return treeMaxmum(root->left);
	}

	pre = node->p;
	while(pre && pre->left == node)
	{
		node = pre; 
		pre = node->p;
	}
	return pre;
}

node_t *treeSuccessor(node_t *root)
{
	node_t *now=root, *pre = NULL;
	if (root->right) {
		return treeMinumum(root->right);
	}
	pre = now->p;
	while(pre && pre->right == now)
	{
		now = pre;
		pre = now->p;
	}
	return pre;
}

static void transplant(node_t **root, node_t *u, node_t *v)
{
	if (NULL == u->p) {
		*root = v;
		v->p = NULL;	
		return;
	}
	if (u->p->right == u){
		u->p->right = v;
	}else if (u->p->left == u){
		u->p->left = v;
	}
	if (NULL != u->p) {
		v->p = u->p;
	}
}

void treeDelete(node_t **root, node_t *t)
{
	node_t *successor = NULL;

	if (!t->left){
		transplant(root, t, t->right);	
	}else if (!t->right) {
		transplant(root, t, t->left);
	}else{
		successor = treeMinumum(t->right);				
		if (t->right != successor) {
			transplant(root, successor, successor->right);
			successor->right = t->right;
			successor->right->p = successor;
		}
		transplant(root, t, successor);
		successor->left = t->left;
		successor->left->p = successor;
	}
	free(t);
}

