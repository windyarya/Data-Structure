/*
Tugas Modul 4 Praktikum Struktur Data - Deque STL
I Putu Windy Arya Sagita - 5027201071
*/

#include <iostream>
#include <deque>
using namespace std;

// fungsi mencari K max
void printKMax(int arr[], int n, int k) {
    // deklarasi dan inisialisasi deque dan variabel
    deque<int> q;
    int i;
    // loop untuk mencari k max value
    for (i = 0; i < n; i++) {
        // untuk melakukan popback jika ada array yg lebih besar daripada nilai back 
        while (!q.empty() && arr[i] > q.back()) {
            q.pop_back();
        }
        q.push_back(arr[i]);
        // untuk melakukan popfront jika nilai front lebih kecil
        if (i >= k && q.front() <= arr[i - k]) {
            q.pop_front();
        }
        // untuk melakukan print jika i itu sudah mencapai k
        if (i >= k - 1) {
            if (i < n - 1) {
                cout << q.front() << " ";
            } else {
                cout << q.front() << endl;
            }
        }
    }
}

// template dari hackerrank
int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
