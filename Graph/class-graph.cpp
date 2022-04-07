/*
I Putu Windy Arya Sagita - 5027201071 - Graph Implementation - Struktur Data E
*/

#include <iostream>
#include <list>
using namespace std;

//array declaration to store city name
string city[] = {"Denpasar", "Badung", "Tabanan", "Jembrana", "Banyuwangi", "Situbondo", "Probolinggo", "Pasuruan", "Sidoarjo", "Surabaya","Jember", "Lumajang", "Malang"};

class graph {
    //private for variable and list declaration
    private:
        int ver;
        list<int>* adj;
    //public for function
    public:
        //function graph to initialize the graph, including linked list
        graph(int vertexA) {
            ver = vertexA;
            adj = new list<int>[vertexA];   //linked list initialization
        }

        //function to add Edge to connect 2 vertices
        void addEdge(int src, int dest) {
            adj[src].push_back(dest);       //pushback the destination to source, ex : src = 1, dest = 2, so 1->2
        }

        //function to print the graph as a list
        void printGraphasList() {
            list<int>::iterator i;          //define the iterator of list so we can go to the next node of list
            int v;

            for (v = 0; v < ver; v++) {
                cout << city[v];
                for (i = adj[v].begin(); i != adj[v].end(); ++i) { 
                    cout << " -> " << city[*i];
                }
                cout << endl;
            }
        }
};

int main() {
    cout << "Simple Graph Implementation: Home to ITS" << endl;

    //graph route by route
    graph g(9);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(8, 9);
    
    g.printGraphasList();

    //ini untuk yang variasi yang ada di video saya, yang bisa milih rute tersebut
    // int i, j;
    // graph gr(1);

    // cout << endl;
    // for (i = 1; i <= 4; ++i) {
    //     gr.addEdge(0, i);
    // }
    // gr.printGraphasList();

    // cout << endl << "Sudah sampai di Banyuwangi nih, mau lewat jalan utara (1) atau selatan (2) nih?" << endl;
    // cout << "Masukan pilihan anda: ";
    // cin >> j;
    // if (j == 1) {
    //     for (i = 5; i < 10; i++) {
    //         gr.addEdge(0, i);
    //     }
    // } else {
    //     for (i = 10; i < 13; i++) {
    //         gr.addEdge(0, i);
    //     }
    //     gr.addEdge(0, 9);
    // }
    
    // cout << endl << "Maka rute dari Denpasar ke Surabaya adalah:" << endl;
    // gr.printGraphasList();

    return 0;
}