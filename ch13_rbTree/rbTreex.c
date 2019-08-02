

#include <string.h>
#include <stdlib.h>

#include "rbTreex.h"


static stRbNode_t gNil={
    .color = RBCOLOR_BLACK,
    .dataPtr = NULL,
};


static void leftRotate(stRbTreeRoot_t *t, stRbNode_t *x)
{
	stRbNode_t *y=t->nil;

	y = x->rightChild;
	x->rightChild = y->leftChild;	
	if (t->nil != y->leftChild){
		y->leftChild->parent = x;
	}

	y->parent = x->parent;
	if (t->root == x){
		t->root = y;
	}else if (x->parent->leftChild == x){
		x->parent->leftChild = y;
	}else{
		x->parent->rightChild = y;
	}

	x->parent = y;
	y->leftChild = x;
}

static void rightRotate(stRbTreeRoot_t *t, stRbNode_t *x)
{
	stRbNode_t *y=t->nil;

	y = x->leftChild;
	x->leftChild = y->rightChild;
	if (y->rightChild != t->nil){
		y->rightChild->parent = x;
	}

	y->parent = x->parent;
	if (t->root == x){
		t->root = y;
	}else if (x->parent->leftChild == x){
		x->parent->leftChild = y;
	}else{
		x->parent->rightChild = y;
	}
	
	x->parent = y;
	y->rightChild = x;
}

static void insertFix(stRbTreeRoot_t *t, stRbNode_t *z)
{
    stRbNode_t *y = t->nil;
    while(z->parent->color == RBCOLOR_RED) {
        if (z->parent == z->parent->parent->leftChild){  //parent node is left subtree
            y = z->parent->parent->rightChild;
            if (y->color == RBCOLOR_RED){   // case 1, uncle is red  
                z->parent->color = RBCOLOR_BLACK;
                y->color = RBCOLOR_BLACK;
                z->parent->parent->color = RBCOLOR_RED;
                z=z->parent->parent;
                continue;
            }else if (z == z->parent->rightChild){   // case 2, uncle is black, node z is parent's right child
                z = z->parent;
                leftRotate(t, z);
            }

            if (z == z->parent->leftChild){  // case 3, uncle is black, node z is parent's left child
                z->parent->color = RBCOLOR_BLACK;
                z->parent->parent->color = RBCOLOR_RED;
                z->parent->parent->rightChild->color = RBCOLOR_BLACK;
                rightRotate(t, z->parent->parent);
            }
        }else{									//parent node is right subtree
			y = z->parent->parent->leftChild;	
			if (y->color == RBCOLOR_RED) {		//case 1, uncle is red
				z->parent->color = RBCOLOR_BLACK;
				y->color = RBCOLOR_BLACK;
				z->parent->parent->color = RBCOLOR_RED;
				z=z->parent->parent;
				continue;
			}else if (z == z->parent->leftChild){ //case 2, uncle is black, node z is parent's left child
				rightRotate(t, z->parent);	
				z=z->parent;
			}

			if (z == z->parent->rightChild){	//case 3, uncle is black, node z is parent's right child
				z->parent->color = RBCOLOR_BLACK;
				z->parent->parent->color = RBCOLOR_RED;
				leftRotate(t, z->parent->parent);
			}
        }
    }
    t->root->color = RBCOLOR_BLACK;
}

static void delFix(stRbTreeRoot_t *t, stRbNode_t *z)
{
    /* TODO */
}


int rbTreexInit(stRbTreeRoot_t *t)
{
    t->nil = &gNil;
    t->root = t->nil;
    return 0; 
}

int rbTreexInsert(stRbTreeRoot_t *t, stRbNode_t *z)
{
    stRbNode_t *y = t->nil, *x = t->nil;

    x = t->root;
    while(x != t->nil){
        y=x;
        if (z->key > x->key){
            x=x->rightChild;
        }else{
            x=x->leftChild;
        }
    }

    if (t->nil == y){
        t->root = z;
    }else if (z->key > y->key){
        y->rightChild = z;
    }else{
        y->leftChild = z;
    }

    z->color = RBCOLOR_RED;
    z->rightChild = t->nil;
    z->leftChild = t->nil;
    z->parent = y;
    insertFix(t, z);
    
    return 0;
}

int rbTreexDel(stRbTreeRoot_t *t, int key)
{
    /* TODO */
    return 0;
}

stRbNode_t* rbTreexSearch(stRbTreeRoot_t *t, int key)
{
    /* TODO */
    return NULL;
}


