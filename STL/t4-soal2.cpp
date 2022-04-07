/*
Tugas Modul 4 Praktikum Struktur Data - Vector Erase
I Putu Windy Arya Sagita - 5027201071
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // inisialisasi dan deklarasi vector dan variabel
    vector<int> v;
    vector<int>::iterator vi;
    int i, a, n, x1, x2, x3;
    cin >> n;
    // untuk memasukan data ke vector
    for (i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    cin >> x1;
    cin >> x2 >> x3;
    // untuk menghapus data di vector sesuai posisi
    v.erase(v.begin() + (x1 - 1));
    // untuk menghapus data di vector dalam rentang posisi
    v.erase(v.begin() + (x2 - 1), v.begin() + (x3 - 1));
    // untuk melakukan print
    cout << v.size() << endl;
    for (vi = v.begin(); vi != v.end(); vi++) {
        cout << *vi << " ";
    }
    return 0;
}
