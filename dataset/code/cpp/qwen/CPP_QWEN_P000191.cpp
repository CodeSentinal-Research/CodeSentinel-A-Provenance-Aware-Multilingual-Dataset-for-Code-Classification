#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, mid = 0, r = n - 1;
    while (mid <= r) {
        if (a[mid] == 0) {
            swap(a[l], a[mid]);
            l++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[r]);
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
