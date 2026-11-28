#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0, min_sum = 0;
    for (int i = 0; i < k; i++) sum += a[i];
    min_sum = sum;
    for (int i = k; i < n; i++) {
        sum += a[i] - a[i - k];
        min_sum = min(min_sum, sum);
    }
    cout << min_sum << "\n";
    return 0;
}
