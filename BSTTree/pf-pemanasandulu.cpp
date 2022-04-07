#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct bstnodeT {
    int data;
    bstnodeT *left, *right;
} BSTNode;

typedef struct bstT {
    BSTNode *root;
    unsigned int size;
} BST;

BSTNode *bstCreateNode(int val) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode *bstInsert(BSTNode *root, int val) {
    if (root == NULL) {
        return bstCreateNode(val);
    }

    if (val < root->data) {
        root->left = bstInsert(root->left, val);
    } else if (val > root->data) {
        root->right = bstInsert(root->right, val);
    }

    return root;
}

BSTNode *bstSearch(BSTNode *root, int val) {
    while (root != NULL) {
        if (val < root->data) {
            root = root->left;
        } else if (val > root->data) {
            root = root->right;
        } else {
            return root;
        }
    }
    return root;
}

bool bstFind(BST *bst, int val) {
    BSTNode *temp = bstSearch(bst->root, val);
    
    if (temp == NULL) {
        return false;
    }

    if (temp->data == val) {
        return true;
    } else {
        return false;
    }
}

void bstInit(BST *bst) {
    bst->root = NULL;
    bst->size = 0u;
}

void bstInserfunc(BST *bst, int val) {
    if (!bstFind(bst, val)) {
        bst->root = bstInsert(bst->root, val);
        bst->size++;
    }
}

void bstFindcp(BSTNode *root, char str[], int val) {
    int flag = 0;

    if (strcmp(str, "child") == 0) {
        while (flag == 0) {
            if (val < root->data) {
                root = root->left;
            } else if (val > root->data) {
                root = root->right;
            } else {
                if (root->left == NULL) {
                    printf("NULL ");
                } else {
                    printf("%d ", root->left->data);
                }

                if (root->right == NULL) {
                    printf("NULL");
                } else {
                    printf("%d", root->right->data);
                }
                flag = 1;
            }
        }
    } else if (strcmp(str, "parent") == 0) {
        BSTNode *temp = NULL;
        
        if (val == root->data) {
            printf("-1");
            flag++;
        }

        while (flag == 0) {
            if (val < root->data) {
                temp = root;
                root = root->left;
            } else if (val > root->data) {
                temp = root;
                root = root->right;
            } else {
                printf("%d", temp->data);
                flag = 1;
            }
        }
    }
}

int main() {
    BST mybst;
    bstInit(&mybst);
    int i, n, a, b;
    char str[20];
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a == 1) {
            scanf("%d", &b);
            bstInserfunc(&mybst, b);
        } else if (a == 2) {
            scanf("%s", str);
            scanf("%d", &b);
            bstFindcp(mybst.root, str, b);
            printf("\n");
        }
    } 

    return 0;
}