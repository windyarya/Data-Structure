/*
Tugas Modul 4 Praktikum Struktur Data - Map STL
I Putu Windy Arya Sagita - 5027201071
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    // deklarasi dan inisialisasi map dan variabel
    map<string, int> m;
    map<string, int>::iterator mi;
    int i, n, q, x, y;
    string name;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> q >> name;
        if (q == 1) { // untuk input nilai
            cin >> x;
            m[name] += x;
        } else if (q == 2) { // untuk menghapus nilai
            m.erase(name);
        } else {
            mi = m.find(name); // untuk mencari nama
            if (mi == m.end()) {
                cout << 0 << endl;
            } else {
                cout << m[name] << endl;
            }
        }
    }
    return 0;
}