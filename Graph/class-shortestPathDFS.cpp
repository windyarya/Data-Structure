/*
Final Project Struktur Data E - Shortest Path DFS
I Putu Windy Arya Sagita - 5027201071
*/
#include <bits/stdc++.h>
using namespace std;

class graph {
public: 
    map<int, bool> vis;
    list<pair<int, int>> *adj;
    vector<int> dist;

    graph(int n) {
        adj = new list<pair<int, int>> [n];
    }

    void addEdge(int src, int dest, int wt) {
        adj[src].push_back(make_pair(dest, wt));
        adj[dest].push_back(make_pair(src, wt));
    }

    void cityName(int n) {
        switch (n) {
            case 0: cout << "Denpasar -> "; break;
            case 1: cout << "Badung -> "; break;
            case 2: cout << "Tabanan -> "; break;
            case 3: cout << "Jembrana -> "; break;
            case 4: cout << "Banyuwangi -> "; break;
            case 5: cout << "Situbondo -> "; break;
            case 6: cout << "Jember -> "; break;
            case 7: cout << "Probolinggo -> "; break;
            case 8: cout << "Lumajang -> "; break;
            case 9: cout << "Pasuruan -> "; break;
            case 10: cout << "Malang -> "; break;
            case 11: cout << "Sidoarjo -> "; break;
            case 12: cout << "Surabaya"; break;
        }
    }

    void dfs(int v) {
        int i;
        int min = 10000;
        int temp;
        for (i = v; i >= 0; i--) {
            vis[i] = true;
        }

        cityName(v);

        if (v == 13) {
            return;
        }

        list<pair<int, int>>::iterator itr;
        for (itr = adj[v].begin(); itr != adj[v].end(); itr++) {
            if (itr->second < min && !vis[itr->first]) {
                min = itr->second;
                temp = itr->first;
                dist.push_back(itr->second);
                dfs(temp);
            }
        }
    }

    void printDistance() {
        cout << endl << "Total Distance: " << accumulate(dist.begin(), dist.end(), 0) << " km";
    }
};

int main() {
    cout << "Shortest Path from Home (Denpasar) to ITS (Surabaya)" << endl;
    
    graph g(13);

    g.addEdge(0, 1, 15);
    g.addEdge(1, 2, 11);
    g.addEdge(2, 3, 72);
    g.addEdge(3, 4, 41);
    g.addEdge(4, 5, 86);
    g.addEdge(4, 6, 113);
    g.addEdge(5, 7, 100);
    g.addEdge(7, 9, 45);
    g.addEdge(9, 11, 42);
    g.addEdge(8, 7, 46);
    g.addEdge(6, 8, 66);
    g.addEdge(8, 10, 92);
    g.addEdge(10, 11, 68);
    g.addEdge(11, 12, 30);

    g.dfs(0);
    g.printDistance();
    return 0;
}
