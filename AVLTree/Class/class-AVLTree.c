/* Implementasi AVL Tree
I Putu Windy Arya Sagita - 5027201071
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//definisikan struktur dari node AVL
typedef struct AVLNode_t
{
    int data;
    struct AVLNode_t *left,*right;
    int height;
}AVLNode;

//struktur AVL
typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

//fungsi untuk membuat node baru
AVLNode* _avl_createNode(int value) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//fungsi untuk mencari element pada tree
AVLNode* _search(AVLNode *root, int value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

//fungsi untuk mendapatkan tinggi tree
int _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

//fungsi untuk menentukan nilai max
int _max(int a,int b){
    return (a > b)? a : b;
}

//fungsi untuk right rotate
AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

//fungsi untuk left rotate
AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

//fungsi jika ada node kiri yang akan dirotate menggunakan right rotate
AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

//fungsi jika ada node kanan yang akan dirotate menggunakan left rotate
AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

//fungsi untuk melakukan left right rotate
AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

//fungsi untuk melakukan right left rotate
AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

//fungsi untuk mendapatkan balance factor
int _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

//fungsi untuk insert elemen ke avl
AVLNode* _insert_AVL(AVL *avl,AVLNode* node,int value) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    int balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) //   
		return _leftRightCaseRotate(node);               
    if(balanceFactor < -1 && value > node->right->data) 
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data) 
        return _rightLeftCaseRotate(node);              
    
    return node;
}

//fungsi untuk mencari dimana ada minimal node
AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

//fungsi untuk meremove element dari avl
AVLNode* _remove_AVL(AVLNode* node,int value){
    if(node==NULL)
        return node;
    if(value > node->data)
    	node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
    	node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

	if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    int balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

//fungsi untuk inisialisasi
void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

//fungsi untuk check apakah node bernilai null atau tidak
bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

//fungsi untuk menentukan apakah ada suatu elemen di tree atau tidak
bool avl_find(AVL *avl, int value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

//fungsi untuk insert
void avl_insert(AVL *avl,int value){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value);
        avl->_size++;
    }

}

//fungsi untuk memanggil remove
void avl_remove(AVL *avl,int value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

//fungsi untuk print secara inorder
void inorder(AVLNode *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(AVLNode *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(AVLNode *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void printpre(AVL *avl) {
    if (avl_isEmpty) {
        preorder(avl->_root);
    }
}

void printin(AVL *avl) {
    if (avl_isEmpty) {
        inorder(avl->_root);
    }
}

void printpost(AVL *avl) {
    if (avl_isEmpty) {
        postorder(avl->_root);
    }
}

int kSmallestElemSumRec(AVLNode *root, int k, int count) {
    if (root == NULL) {
        return 0;
    }
    if (count > k) {
        return 0;
    }

    int res = kSmallestElemSumRec(root->left, k, count);
    if (count >= k) {
        return res;
    }
    res += root->data;

    count++;
    if (count >= k) {
        return res;
    }
    return res + kSmallestElemSumRec(root->right, k, count);
}

int kSmallestElemSum(AVL *avl, int k) {
    int count = 0;
    int sum;
    sum = kSmallestElemSumRec(avl->_root, k, count);
    return sum;
}

int main() {
    AVL myavl;
    avl_init(&myavl);

    int i;
    int n;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        avl_insert(&myavl, x);
        printf("The current tree consist of ");
        printin(&myavl);
        printf("\n");
    }

    int k;
    printf("Enter k: ");
    scanf("%d", &k);
    printf("Sum of %d-smallest element of tree is %d", k, kSmallestElemSum(&myavl, k));
    return 0;
}