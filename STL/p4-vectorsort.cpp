#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    vector<int>::iterator vi;
    int n, i, x;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }  

    sort(v.begin(), v.end());

    for (vi = v.begin(); vi != v.end(); vi++) {
        cout << *vi << " ";
    }
    return 0;
}