#include <iostream>
#include <algorithm>

using namespace std;

bool makesquare(int a[], int n) {
    if (n == 0) return false;
    int m = a[0];
    for (int i = 1; i < n; i++) {
        m += a[i];
    }
    if (m % 4 != 0) return false;
    sort(a, a + n);
    if (a[0] != 0) return false;
    int side = m / 4;
    int count[4] = {0, 0, 0, 0};
    for (int i = n - 1; i >= 0; i--) {
        if (count[3] + a[i] > side) return false;
        if (count[2] + a[i] > side) return false;
        if (count[1] + a[i] > side) return false;
        if (count[0] + a[i] > side) return false;
        count[3] += a[i];
        if (count[3] == side) return true;
        count[2] += a[i];
        if (count[2] == side) return true;
        count[1] += a[i];
        if (count[1] == side) return true;
        count[0] += a[i];
        if (count[0] == side) return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << makesquare(a, n);
    return 0;
}