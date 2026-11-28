#include <iostream>
using namespace std;

void merge(int a[], int b[], int m, int n) {
    int i = 0, j = 0;

    while(i < m && j < n) {
        if(a[i] < b[j])
            cout << a[i++] << " ";
        else
            cout << b[j++] << " ";
    }

    while(i < m)
        cout << a[i++] << " ";

    while(j < n)
        cout << b[j++] << " ";
}

int main() {
    int n, m;
    cout << "Enter number of elements in first array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements in sorted order of first array: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter number of elements in second array: ";
    cin >> m;
    int b[m];
    cout << "Enter elements in sorted order of second array: ";
    for(int i = 0; i < m; i++)
        cin >> b[i];

    merge(a, b, m, n);

    return 0;
}