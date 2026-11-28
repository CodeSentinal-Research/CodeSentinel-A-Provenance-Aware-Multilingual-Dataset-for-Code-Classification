#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, m;
    cin >> n >> l >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + a[i];
    long long max_sum = 0;
    for (int i = l; i <= n - m; i++) {
        long long s1 = prefix[i] - prefix[i - l];
        long long s2 = prefix[i + m] - prefix[i];
        max_sum = max(max_sum, s1 + s2);
    }
    cout << max_sum << "\n";
    return 0;
}
