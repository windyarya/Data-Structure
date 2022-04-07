/*TUgas Praktikum Modul 3 - SDITSAVL SPOJ
I Putu Windy Arya Sagita - 5027201071
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int val;
    struct node *left;
    struct node *right;
    int leftChild;
    int rightChild;
    int height;
} node;

int flag;

node *newNode(int val, int leftChild, int rightChild) {
    node *temp = (node*)malloc(sizeof(node));

    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    temp->leftChild = leftChild;
    temp->rightChild = rightChild;

    return temp;
}

int getHeight(node *root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

int getBF(node *root) {
    if (root == NULL) {
        return 0;
    } else {
        return getHeight(root->left) - getHeight(root->right);   
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

node *rightRotate(node *avl) {
    node *temp = avl->left;
    node *temp2 = temp->right;

    temp->right = avl;
    avl->left = temp2;

    avl->height = max(getHeight(avl->left), getHeight(avl->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

    if (temp2 != NULL) {
        avl->leftChild = temp2->leftChild + temp2->rightChild + 1;
    } else {
        avl->leftChild = 0;
    }
    temp->rightChild = avl->leftChild + avl->rightChild + 1;

    return temp;
}

node *leftRotate(node *avl) {
    node *temp = avl->right;
    node *temp2 = temp->left;

    temp->left = avl;
    avl->right = temp2;

    avl->height = max(getHeight(avl->left), getHeight(avl->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

    if (temp2 != NULL) {
        avl->rightChild = temp2->leftChild + temp2->rightChild + 1;
    } else {
        avl->rightChild = 0;
    }
    temp->leftChild = avl->leftChild + avl->rightChild + 1;

    return temp;
}

node *insert(node *root, int val) {
    if (root == NULL) {
        return newNode(val, 0, 0);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
        root->leftChild++;
    } else if (val > root->val) {
        root->right = insert(root->right, val);
        root->rightChild++;
    } else {
        return root;
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int bal = getBF(root);

    if (bal > 1 && val < root->left->val) {
        return rightRotate(root);
    }
    if (bal < -1 && val > root->right->val) {
        return leftRotate(root);
    }
    if (bal > 1 && val > root->left->val) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (bal < -1 && val < root->right->val) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int findbVal(node *root, int val) {
    if (root != NULL) {
        if (val > root->val) {
            return root->leftChild + 1 + findbVal(root->right, val);
        } else if (val < root->val) {
            findbVal(root->left, val);
        } else {
            return root->leftChild;
        }
    } else {
        flag = 1;
        return -1;
    }
}

void inOrder(node *root) {
    if (root != NULL) {
        printf("%d %d %d\n", root->val, root->leftChild, root->rightChild);
        inOrder(root->left);
        inOrder(root->right);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    node *root = NULL;
    for (i = 0; i < n; i++) {
        int op, num, pos;
        scanf("%d%d", &op, &num);
        if (op == 1) {
            root = insert(root, num);
        }
        if (op == 2) {
            flag = 0;
            pos = findbVal(root, num) + 1;
            if (flag) {
                printf("Data tidak ada\n");
            } else {
                printf("%d\n", pos);
            }
        }
    }
    return 0;
}