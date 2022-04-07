#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<int> v;
    vector<int>::iterator vi;
    int i, j, n, x, q;
    char c;

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> q;
        for (j = 0; j < q; j++) {
            cin >> c;
            if (c == 'a') {
                cin >> x;
                v.push_back(x);
            } else if (c == 'b') {
                sort(v.begin(), v.end());
            } else if (c == 'c') {
                reverse(v.begin(), v.end());
            } else if (c == 'd') {
                cout << v.size() << " ";
            } else if (c == 'e') {
                for (vi = v.begin(); vi != v.end(); vi++) {
                    cout << *vi << " ";
                }
            } else if (c == 'f') {
                sort(v.begin(), v.end(), greater<int>());
                // for (vi = v.begin(); vi != v.end(); vi++) {
                //     cout << *vi << " ";
                // }
            }
        }
        v.clear();
        cout << endl;
    }
    return 0;
}