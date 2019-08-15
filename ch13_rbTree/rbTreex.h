

#ifndef RBTREEX_H
#define RBTREEX_H


#define RBCOLOR_BLACK   (1)
#define RBCOLOR_RED     (0)


typedef int* stRbTreeData_t;

typedef struct _rbNode_t
{
    int color;
    stRbTreeData_t dataPtr;
    int key;
    struct _rbNode_t *parent;
    struct _rbNode_t *leftChild;
    struct _rbNode_t *rightChild;
}stRbNode_t;

typedef struct _rbTree_t
{
    stRbNode_t *root;
    stRbNode_t *nil;
}stRbTreeRoot_t;


int rbTreexInit(stRbTreeRoot_t *t);

int rbTreexInsert(stRbTreeRoot_t *t, stRbNode_t *z);

int rbTreexDel(stRbTreeRoot_t *t, stRbNode_t *z);

stRbNode_t *rbTreexMin(stRbTreeRoot_t *t, stRbNode_t *z);

stRbNode_t* rbTreexSearch(stRbTreeRoot_t *t, int key);

void rbTreexInorderWalk(stRbTreeRoot_t *t);

void rbTreexPreorderWalk(stRbTreeRoot_t *t);

void rbTreexPostorderWalk(stRbTreeRoot_t *t);


#endif
