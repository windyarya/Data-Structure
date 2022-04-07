/*Tugas Praktikum Modul 3 - Self Balancing Tree Hackerrank
I Putu Windy Arya Sagita - 5027201071
*/

/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node* newAVLNode(int data) {
    node* treeNode = (node*)malloc(sizeof(node));
    treeNode->val = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    treeNode->ht = 0;
    return treeNode;
}

int heightSubtree(node *subtree) {
    if (subtree == NULL) {
        return -1;
    }
    return subtree->ht;
}

int getBF(node *avl) {
    if (avl == NULL) {
        return 0;
    }
    return heightSubtree(avl->left) - heightSubtree(avl->right);
}

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

node* rightRotate(node *avl) {
    node* temp = avl->left;
    node* temp2 = temp->right;
    
    temp->right = avl;
    avl->left = temp2;
    
    avl->ht = maxVal(heightSubtree(avl->left), heightSubtree(avl->right)) + 1;
    temp->ht = maxVal(heightSubtree(temp->left), heightSubtree(temp->right)) + 1;
    
    return temp;
}

node* leftRotate(node *avl) {
    node* temp = avl->right;
    node* temp2 = temp->left;
    
    temp->left = avl;
    avl->right = temp2;
    
    avl->ht = maxVal(heightSubtree(avl->left), heightSubtree(avl->right)) + 1;
    temp->ht = maxVal(heightSubtree(temp->left), heightSubtree(temp->right)) + 1;
    
    return temp;
}

node * insert(node * root,int val)
{
	if (root == NULL) {
        return newAVLNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    
    root->ht = 1 + maxVal(heightSubtree(root->left), heightSubtree(root->right));
    
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