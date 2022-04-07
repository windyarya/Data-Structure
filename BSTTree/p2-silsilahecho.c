#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct bstNode {
    int key;
    struct bstNode \
        *kiri, *kanan;
} BSTNode;

typedef struct bstTree {
    BSTNode *root;
    unsigned int size;
} BSTTree;

BSTNode* bst_nodeBaru(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->kiri = newNode->kanan = NULL;
    return newNode;
}

BSTNode* bst_masukin(BSTNode *root, int value) {
    if (root == NULL)
        return bst_nodeBaru(value);

    if (value < root->key)
        root->kiri = bst_masukin(root->kiri, value);
    else if (value > root->key)
        root->kanan = bst_masukin(root->kanan, value);

    return root;
}

BSTNode* bst_cari(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->kiri;
        else if (value > root->key)
            root = root->kanan;
        else
            return root;
    }
    return root;
}

BSTNode* bst_nodeTerkecil(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->kiri != NULL)
        currNode = currNode->kiri;

    return currNode;
}

BSTNode* bst_hapus(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->kanan = bst_hapus(root->kanan, value);
    else if (value < root->key)
        root->kiri = bst_hapus(root->kiri, value);
    else {

        if (root->kiri == NULL) {
            BSTNode *rightChild = root->kanan;
            free(root);
            return rightChild;
        }
        else if (root->kanan == NULL) {
            BSTNode *leftChild = root->kiri;
            free(root);
            return leftChild;
        }

        BSTNode *temp = bst_nodeTerkecil(root->kanan);
        root->key     = temp->key;
        root->kanan   = bst_hapus(root->kanan, temp->key);
    }
    return root;
}

void __bst__inorder(BSTNode *root) {
    if (root) {
        __bst__inorder(root->kiri);
        printf("%d ", root->key);
        __bst__inorder(root->kanan);
    }
}

void __bst__postorder(BSTNode *root) {
    if (root) {
        __bst__postorder(root->kiri);
        __bst__postorder(root->kanan);
        printf("%d ", root->key);
    }
}

void __bst__preorder(BSTNode *root) {
    if (root) {
        printf("%d ", root->key);
        __bst__preorder(root->kiri);
        __bst__preorder(root->kanan);
    }
}

void bst_init(BSTTree *bst) {
    bst->root = NULL;
    bst->size = 0u;
}

bool bst_isEmpty(BSTTree *bst) {
    return bst->root == NULL;
}

bool bst_find(BSTTree *bst, int value) {
    BSTNode *temp = bst_cari(bst->root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BSTTree *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->root = bst_masukin(bst->root, value);
        bst->size++;
    }
}

void bst_remove(BSTTree *bst, int value) {
    if (bst_find(bst, value)) {
        bst->root = bst_hapus(bst->root, value);
        bst->size--;
    }
}

void bst_inorder(BSTTree *bst) {
    __bst__inorder(bst->root);
}

void bst_postorder(BSTTree *bst) {
    __bst__postorder(bst->root);
}

void bst_preorder(BSTTree *bst) {
    __bst__preorder(bst->root);
}


int bst_left(BSTTree *bst, int value) {
    BSTNode *temp = bst_cari(bst->root, value);
    if(temp->key == value) {
        if(temp->kiri!=NULL) {
            temp = temp->kiri;
            return temp->key;
        }
    }
    return -1;
}

int bst_right(BSTTree *bst, int value) {
    BSTNode *temp = bst_cari(bst->root, value);
    if(temp->key == value) {
        if(temp->kanan!=NULL) {
            temp = temp->kanan;
            return temp->key;
        }
    }
    return -1;
}

BSTNode* bst_cariParent(BSTNode *root, int value) {
    BSTNode *temp = NULL;
    while (root != NULL) {
        if (value < root->key) {
            temp = root;
            root = root->kiri;
        }else if (value > root->key){
            temp = root;
            root = root->kanan;
        }else{
            return temp;
        }
    }
    return temp;
}

int bst_findParent(BSTTree *bst, int value) {
    BSTNode *temp = bst_cariParent(bst->root, value);
    if(temp == NULL) {
        return -1;
    } else {
        return temp->key;
    }
}

int main()
{
    BSTTree set;
    bst_init(&set);

    int Z, ppsoft;
    scanf("%d", &Z);

    for(int i=0; i<Z; i++) {
        scanf("%d", &ppsoft);
        if(ppsoft == 1) {
            int W;
            scanf("%d", &W);
            bst_insert(&set, W);
        } else if(ppsoft == 2) {
            int X;
            char S[100];
            scanf("%s %d", S, &X);
            if(strcmp(S, "anaK") == 0) {
                int A, B;
                A = bst_left(&set, X);
                B = bst_right(&set, X);
                if(A<1 && B<1) {
                    printf("diManakah Anak- aNakkuu :(\n");
                    break;
                }
                if(A<1) {
                    printf("- ");
                } else {
                    printf("%d ", A);
                }
                if(B<1) {
                    printf("-\n");
                } else {
                    printf("%d\n", B);
                }
            } else if(strcmp(S, "ibU") == 0) {
                int A;
                A = bst_findParent(&set, X);
                if(A == -1) {
                    printf("Aku adalaH sesepuH\n");
                } else {
                    printf("%d\n", A);
                }
            }
        }
    }
    return 0;
}