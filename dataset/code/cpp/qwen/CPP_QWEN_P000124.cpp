#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> res(n, 1);
    long long prefix = 1;
    for (int i = 0; i < n; i++) {
        res[i] *= prefix;
        prefix *= a[i];
    }
    long long suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        res[i] *= suffix;
        suffix *= a[i];
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << (i == n - 1 ? "\n" : " ");
    }
    return 0;
}
