#include <iostream>
#include <list>
using namespace std;

class graph {
    private:
        int ver;
        list<int>* adj;
    public:
        graph(int v) {
            ver = v;
            adj = new list<int>[v];  
        }

        void addEdge(int src, int dest) {
            adj[src].push_back(dest);       
        }

        void bfs(int s) {
            bool *vis = new bool[ver];
            int j;
            for (j = 0; j < ver; j++) {
                vis[j] = false;
            }

            list<int> queue;

            vis[s] = true;
            queue.push_back(s);

            list<int>::iterator i;

            while (!queue.empty()) {
                s = queue.front();
                cout << s << " -> ";
                queue.pop_front();

                for (i = adj[s].begin(); i != adj[s].end(); ++i) {
                    if (!vis[*i]) {
                        vis[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }
};

int main() {
    int n, v, i, j, a, b;
    cin >> v;
    cin >> n;
    graph g(v);

    for (i = 0; i < n; i++) {
        cin >> a >> b;
        g.addEdge(a, b);
    }

    cin >> j;
    g.bfs(j);
    cout << "END";

    return 0;
}