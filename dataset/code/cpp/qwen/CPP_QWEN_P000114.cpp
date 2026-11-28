#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    rotate(a.begin(), a.begin() + k, a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
