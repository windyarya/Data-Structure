/*
I Putu Windy Arya Sagita - 5027201071
*/

#include <iostream>
#include <list>
#include <map>
using namespace std;

/*
0 -> Denpasar, 1 -> Badung, 2 -> Tabanan, 3 -> Jembrana
4 -> Banyuwangi, 5 -> Situbondo, 6 -> Probolinggo, 7 -> Pasuruan
8 -> Sidoarjo, 9 -> Surabaya
10 -> Jember, 11 -> Lumajang, 12 -> Malang
*/

class graph {                           
    public:
        map<int, bool> vis;
        map<int, list<int>> adj;       

        void addEdge(int src, int dest) {
            adj[src].push_back(dest);       
        }

        void bfs(int s) {
            int j;
            for (j = 0; j < adj.size(); j++) {
                vis[j] = false;
            }

            list<int> queue;
            vis[s] = true;
            queue.push_back(s);
            list<int>::iterator i;

            while (!queue.empty()) {
                s = queue.front();
                cout << s << " ";
                queue.pop_front();

                for (i = adj[s].begin(); i != adj[s].end(); ++i) {
                    if (!vis[*i]) {
                        vis[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }

        void dfs(int s) {
            vis[s] = true;
            cout << s << " ";
            list<int>::iterator i;
            for (i = adj[s].begin(); i != adj[s].end(); i++) {
                if (!vis[*i]) {
                    dfs(*i);
                }
            }
        }
};

int main() {
    cout << "Graph Traversal: Home to ITS" << endl;

    graph g;

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 10);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    g.addEdge(10, 11);
    g.addEdge(11, 12);
    g.addEdge(11, 6);
    g.addEdge(12, 7);
    
    cout << endl << "DFS Traversal: ";
    g.dfs(0);
    cout << endl << "BFS Traversal: ";
    g.bfs(0);

    return 0;
}