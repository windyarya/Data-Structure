#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    vector<int>::iterator vi;
    int i, n, q, x, y;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }

    cin >> q;
    for (i = 0; i < q; i++) {
        cin >> y;
        vi = find(v.begin(), v.end(), y);
        if (vi != v.end()) {
            int index = distance(v.begin(), vi);
            cout << "Ya " << index+1 << endl; 
        } else {
            while (true) {
                vi = find(v.begin(), v.end(), y++);
                if (vi != v.end()) {
                    break;
                }
            }
            int index = distance(v.begin(), vi);
            cout << "Tidak " << index+1 << endl;
        }
    }
    return 0;
}