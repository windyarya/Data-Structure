#include <bits/stdc++.h>
using namespace std;

class graph {
    public:
    vector<int> vec[100005];
    bool vis[100005];

    void addEdge(int src, int dest) {
        vec[src].push_back(dest);
        vec[dest].push_back(src);
    } 

    int cekKota(int n) {
        int jml = 0;
        int i;
        for (i = 0; i < vec[n].size(); i++) {
            if (vis[vec[n][i]] == false) {
                vis[vec[n][i]] = true;
                jml += cekKota(vec[n][i]);
            }
        }
        return jml + 1;
    }

    void reset() {
        int i;
        for (i = 0; i < 100001; i++) {
            vec[i].clear();
            vis[i] = false;
        }
        // vec2.clear();
    }

    int cekbiaya(int a) {
        int i;
        vector<int> vec2;
        for (i = 1; i <= a; i++) {
            if (vis[i] == false) {
                vis[i] = true;
                vec2.push_back(cekKota(i));
            }
        }
        // vector<int>::iterator itr;
        // for (itr = vec2.begin(); itr != vec2.end(); itr++) {
        //     cout << *itr << " ";
        // }

        sort(vec2.begin(), vec2.end(), greater<int>());
        int total = 0;
        for (i = 0; i < vec2.size(); i++) {
            total += (vec2.at(i)*(i+1));
        }
        return total;
    }
};

int main() {
    int i, j, n, a, b, x, y;
    graph g;
    cin >> n;

    for (i = 0; i < n; i++) {
        g.reset();
        cin >> a >> b;
        for (j = 0; j < b; j++) {
            cin >> x >> y;
            g.addEdge(x, y);
        }
        // g.cekbiaya(a);
        cout << "Kasus #" << i+1 << ": " << g.cekbiaya(a) << endl;
    }

    return 0;
}