#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stable_partition(a.begin(), a.end(), [](int x) { return x % 2 == 0; });
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
