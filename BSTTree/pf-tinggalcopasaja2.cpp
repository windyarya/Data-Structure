#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> vec;

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

void bstInorder(BSTNode *root) {
    if (root) {
        bstInorder(root->left);
        vec.push_back(root->data);
        bstInorder(root->right);
    }
}

void bstPostorder(BSTNode *root) {
    if (root) {
        bstPostorder(root->left);
        bstPostorder(root->right);
        vec.push_back(root->data);
    }
}

void bstPreorder(BSTNode *root) {
    if (root) {
        vec.push_back(root->data);
        bstPreorder(root->left);
        bstPreorder(root->right);
    }
}

void traversaltree(BST *bst, string str, int index) {
    vec.clear();
    if (str == "inorder") {
        bstInorder(bst->root);
        cout << vec.at(index - 1);
    } else if (str == "preorder") {
        bstPreorder(bst->root);
        cout << vec.at(index - 1);
    } else if (str == "postorder") {
        bstPostorder(bst->root);
        cout << vec.at(index - 1);
    }
}

int main() {
    BST mybst;
    bstInit(&mybst);
    int i, n, a, b;
    string str;;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            bstInserfunc(&mybst, b);
        } else if (a == 2) {
            cin >> str >> b;
            traversaltree(&mybst, str, b);
            cout << endl;
        }
    } 

    return 0;
}