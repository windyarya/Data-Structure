/*
Tugas Modul 4 Praktikum Struktur Data - Set STL
I Putu Windy Arya Sagita - 5027201071
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    // deklarasi dan inisialisasi set dan variabel
    set<int> s;
    set<int>::iterator si;
    int i, n, q, t;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> q >> t;
        if (q == 1) { // untuk insert ke set
            s.insert(t);
        } else if (q == 2) { // untuk menghapus element di set
                s.erase(t);
        } else {
            si = s.find(t); // untuk mencari element di set
            if (si == s.end()) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
