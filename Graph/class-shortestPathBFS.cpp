/*
Final Project Struktur Data E - Shortest Path BFS
I Putu Windy Arya Sagita - 5027201071
*/
#include <iostream>
#include <limits>
using namespace std;

#define V 20

class graph {
    int ver;
    int graphc[V][V];
public:
    graph(int v) {
        this->ver = v;
        int i, j;
        for (i = 0; i < ver; i++) {
            for (j = 0; j < ver; j++) {
                graphc[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int wt) {
        graphc[src][dest] = wt;
    }

    void cityName(int n) {
        switch (n) {
            case 1: cout << "Denpasar -> "; break;
            case 2: cout << "Badung -> "; break;
            case 3: cout << "Tabanan -> "; break;
            case 4: cout << "Jembrana -> "; break;
            case 5: cout << "Banyuwangi -> "; break;
            case 6: cout << "Situbondo -> "; break;
            case 7: cout << "Jember -> "; break;
            case 8: cout << "Probolinggo -> "; break;
            case 9: cout << "Lumajang -> "; break;
            case 10: cout << "Pasuruan -> "; break;
            case 11: cout << "Malang -> "; break;
	        case 12: cout << "Sidoarjo -> "; break;
            case 13: cout << "Surabaya"; break;
        }
    }

    void printCity(int shortp[], int x) {
        if (shortp[x] > -1) {
            printCity(shortp, shortp[x]);
            cityName(x);
        }

        if (shortp[x] == -1) {
            cityName(x);
        }
    }

    void printPath(int dist[], int shortp[]) {
        int temp, i;
        for (i = 1; i < V; i++) {
            if (i == 13) {
                temp = dist[i];
                printCity(shortp, i);
            }
        }

        cout << endl << "Total Distance: " << temp - 1 << " km";
    }

    int minDist(int dist[], bool vis[]) {
        int min = INT_MAX;
        int minIndex, i;

        for (i = 0; i < V; i++) {
            if (vis[i] == false && dist[i] <= min) {
                min = dist[i];
                minIndex = i;
            }
        }

        return minIndex;
    }

    void bfsDijkstra(int src) {
        int dist[V];
        bool vis[V];
        int shortp[V];
        int i, j;

        for (i = 1; i < V; i++) {
            shortp[src] = -1;
            dist[i] = INT_MAX;
            vis[i] = false;
        }

        dist[src] = 0;

        for (i = 0; i < V - 1; i++) {
            int k = minDist(dist, vis);
            vis[k] = true;
            for (j = 0; j < V; j++) {
                if (!vis[j] && graphc[k][j] && dist[k] + graphc[k][j] < dist[j]) {
                    shortp[j] = k;
                    dist[j] = dist[k] + graphc[k][j];
                }
            }
        }
        printPath(dist, shortp);
    }
};


int main() {
	cout << "Shortest Path from Home (Denpasar) to ITS (Surabaya)" << endl;
	
	graph g(V);
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(3, 4, 72);
    g.addEdge(4, 5, 41);
    g.addEdge(5, 6, 86);
    g.addEdge(5, 7, 113);
    g.addEdge(6, 8, 100);
    g.addEdge(8, 10, 45);
    g.addEdge(10, 12, 42);
    g.addEdge(8, 7, 46);
    g.addEdge(7, 9, 66);
    g.addEdge(9, 11, 92);
    g.addEdge(11, 12, 68);
    g.addEdge(12, 13, 30);

	g.bfsDijkstra(0);

	return 0;
}
