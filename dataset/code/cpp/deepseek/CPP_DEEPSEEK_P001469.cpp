#include <iostream>
using namespace std;

void mergeSortedArrays(int a[], int b[], int n, int m) {
    int i = 0, j = 0;
    int c[n + m];
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            c[i + j] = a[i];
            i++;
        } else {
            c[i + j] = b[j];
            j++;
        }
    }
    while (i < n) {
        c[i + j] = a[i];
        i++;
    }
    while (j < m) {
        c[i + j] = b[j];
        j++;
    }
    for (int i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    mergeSortedArrays(a, b, n, m);
    return 0;
}