

#include <string.h>
#include <stdlib.h>

#include "rbTreex.h"


static const stRbNode_t gNil={
    .color = RBCOLOR_BLACK,
    .dataPtr = NULL,
};


static void leftRotate(stRbTreeRoot_t *t, stRbNode_t *z)
{
    /* TODO */
}

static void rightRotate(stRbTreeRoot_t *t, stRbNode_t *z)
{
    /* TODO */
}

static void insertFix(stRbTreeRoot_t *t, stRbNode_t *z)
{
    while(z->parent->color == RBCOLOR_RED) {
        if (z->parent == z->parent->parent->leftChild){  //left subtree
            stRbNode_t *y;
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
                rightRotate(t, z);
            }
        }else{
            /* TODO */
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


