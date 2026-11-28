#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long max_prod = a[0], min_prod = a[0], res = a[0];
    for (int i = 1; i < n; i++) {
        long long t1 = max_prod * a[i], t2 = min_prod * a[i];
        max_prod = max({(long long)a[i], t1, t2});
        min_prod = min({(long long)a[i], t1, t2});
        res = min(res, min_prod);
    }
    cout << res << "\n";
    return 0;
}
