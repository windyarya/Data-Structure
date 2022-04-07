#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, int> toy;
    int n, q, i, j, a, p, x, y;
    cin >> n >> q;

    for (i = 0; i < n; i++) {
        cin >> a;
        toy.insert({i, a});
    }

    for (i = 0; i < q; i++) {
        cin >> p;
        if (p == 1) {
            cin >> x >> y;
            toy.at(x) = y;
        } else if (p == 2) {
            cin >> x >> y;
            int max = toy.at(x);
            for (j = x; j < y; j++) {
                if (toy.at(j) > max) {
                    max = toy.at(j);
                }
            }
            cout << max << endl;
        }
    }
    
    return 0;
}