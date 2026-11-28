#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    long long left_sum = 0;
    for (int i = 0; i < n; i++) {
        if (left_sum == total - left_sum - a[i]) {
            cout << i + 1 << "\n";
            return 0;
        }
        left_sum += a[i];
    }
    cout << -1 << "\n";
    return 0;
}
