

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

static void transplant(stRbTreeRoot_t *t, stRbNode_t *u, stRbNode_t *v)
{
    if (t->root == u) {
        t->root = v;
    }else if (u->parent->leftChild == u){
        u->parent->leftChild = v;
    }else{
        u->parent->rightChild = v;
    }
    v->parent = u->parent;
}

static void delFix(stRbTreeRoot_t *t, stRbNode_t *x)
{
	stRbNode_t *w = t->nil;
	while(t->root != x && x->color == RBCOLOR_BLACK){
		if (x == x->parent->leftChild){
			w = x->parent->rightChild;
			if (w->color == RBCOLOR_RED){					//case 1, x's brother w,color is red
				x->parent->color = RBCOLOR_RED;
				w->color = RBCOLOR_BLACK;
				w=w->leftChild;
				leftRotate(t, x->parent);
			}
			if (w->leftChild->color == RBCOLOR_BLACK && 	//case2, x's brother w, color is black. w's left color is black, w's right color is black
				w->rightChild->color == RBCOLOR_BLACK){
				w->color = RBCOLOR_RED;
				x = x->parent;
			}else{
				if (w->rightChild->color == RBCOLOR_BLACK){	//case3, x's brother w, color is black, w's left color is red, w's right color is black
					w->color = RBCOLOR_RED;
					w->leftChild->color = RBCOLOR_BLACK;
					rightRotate(t, w);	
					w = w->parent;
				}
				w->color = x->parent->color;				//case4, x's brother w, color is black, w's right color is red
				x->parent->color = RBCOLOR_BLACK;
				w->rightChild->color = RBCOLOR_BLACK;
				leftRotate(t, x->parent);
				x = t->root;
			}
		}else{

		}
	}
	x->color = RBCOLOR_BLACK;
}

int rbTreexDel(stRbTreeRoot_t *t, stRbNode_t *z)
{
    int yoriColor;
    stRbNode_t *y = t->nil, *x= t->nil;

    yoriColor = z->color;
    y = z;
    if (z->leftChild == t->nil){            //z left subtree is null
        transplant(t, z, z->rightChild);    
        x = z->rightChild;
    }else if (z->rightChild == t->nil){     //z right subtree is null
        transplant(t, z, z->leftChild);
        x = z->leftChild;
    }else{                                  //z two subtree is not null
        y = rbTreexMin(t, z->rightChild);
        yoriColor = y->color;
        x=y->rightChild;
        if(z->rightChild == y){
        }else{
            transplant(t, y, x);
            y->rightChild = z->rightChild;
            z->rightChild->parent = y;
        }
        transplant(t, z, y);
        y->leftChild = z->leftChild;
        z->leftChild->parent = y;
        y->color = z->color;
    }
    if (yoriColor == RBCOLOR_BLACK){
        delFix(t, x);
    }
    return 0;
}

stRbNode_t *rbTreexMin(stRbTreeRoot_t *t, stRbNode_t *z)
{
    while(z->leftChild != t->nil){
        z = z->leftChild;
    }
    return z;
}

stRbNode_t* rbTreexSearch(stRbTreeRoot_t *t, int key)
{
    /* TODO */
    return NULL;
}

static void inorderWalk(stRbTreeRoot_t *t, stRbNode_t *x)
{
    if (x != t->nil){
        inorderWalk(t, x->leftChild);
        printf("Key:%d\r\n", x->key);
        inorderWalk(t, x->rightChild);
    }
}

static void preorderWalk(stRbTreeRoot_t *t, stRbNode_t *x)
{
    if (x != t->nil){
        printf("Key:%d\r\n", x->key);
        inorderWalk(t, x->leftChild);
        inorderWalk(t, x->rightChild);
    }
}

static void postorderWalk(stRbTreeRoot_t *t, stRbNode_t *x)
{
    if (x != t->nil){
        inorderWalk(t, x->leftChild);
        inorderWalk(t, x->rightChild);
        printf("Key:%d\r\n", x->key);
    }
}


void rbTreexInorderWalk(stRbTreeRoot_t *t)
{
    printf("Inorder:\r\n");
    inorderWalk(t, t->root); 
    printf("\r\n");
}

void rbTreexPreorderWalk(stRbTreeRoot_t *t)
{
    printf("Preorder:\r\n");
    preorderWalk(t, t->root); 
    printf("\r\n");
}

void rbTreexPostorderWalk(stRbTreeRoot_t *t)
{
    printf("Postorder:\r\n");
    postorderWalk(t, t->root); 
    printf("\r\n");
}


