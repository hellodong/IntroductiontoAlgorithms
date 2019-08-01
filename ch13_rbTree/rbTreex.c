

#include <string.h>
#include <stdlib.h>

#include "rbTreex.h"


static const stRbNode_t gNil={
    .color = RBCOLOR_BLACK,
    .dataPtr = NULL,
};

static stRbNode_t *Nil=&gNil;


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
    /* TODO */
}

static void delFix(stRbTreeRoot_t *t, stRbNode_t *z)
{
    /* TODO */
}


int rbTreexInit(stRbTreeRoot_t *t)
{
    t->root = Nil;
    return 0; 
}

int rbTreexInsert(stRbTreeRoot_t *t, stRbNode_t *z)
{
    stRbNode_t *y = Nil, *x = Nil;

    x = t->root;
    while(x != Nil){
        y=x;
        if (z->key > x->key){
            x=x->rightChild;
        }else{
            x=x->leftChild;
        }
    }

    if (Nil == y){
        t->root = z;
    }else if (z->key > y->key){
        y->rightChild = z;
    }else{
        y->leftChild = z;
    }

    z->color = RBCOLOR_RED;
    z->rightChild = Nil;
    z->leftChild = Nil;
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


