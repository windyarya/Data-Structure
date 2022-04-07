/* Tugas Praktikum Struktur Data Modul 2 - BST Counting e-Olymp
I Putu WIndy Arya Sagita - 5027201071*/

#include <stdio.h>

#define MAX 1001

struct Node {
    int val;
    int left, right;
    int nLeft, nRight;  
} n[MAX];

int nCk[MAX][MAX], s, m = 1000003;

void add(int &root, int v) {
    if (root == -1){
        n[root = s++] = (Node){v,-1,-1,0,0};
    } else {
        Node &r = n[root];
        if (v < r.val) {
            add(r.left, v), r.nLeft++;  
		} else {
            add(r.right, v), r.nRight++;  
    	}
	}
}

long long f(int root) {
    if (root == -1) {
		return 1;
	}
    Node &r = n[root];
    long long ret = nCk[r.nLeft + r.nRight][r.nLeft]; 
    ret = ret * f(r.left) % m;
    ret = ret * f(r.right) % m;
    return ret;
}

int main() {
	int i, j;
    nCk[0][0] = 1;
    for (i = 1; i < MAX; i++) {
        nCk[i][0] = 1;
        for (j = 1; j < MAX; j++) {
            nCk[i][j] = (nCk[i-1][j-1] + nCk[i-1][j]) % m;
    	}
	}

    int TC;
    scanf("%d", &TC);
    while (TC--) {
        int N, T, value, root=-1; s = 1;
        scanf("%d %d", &N, &T);
        for (i = 0; i < N; i++) { 
			scanf("%d",&value);
			add(root, value);
		}
        printf("%d\n", int(f(root) * nCk[T][N] % m)); 
    }
}