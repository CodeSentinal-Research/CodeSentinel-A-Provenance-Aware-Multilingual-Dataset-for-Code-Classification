#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long max_sum = LLONG_MIN, cur = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] > a[i - 1]) {
            cur += a[i];
        } else {
            cur = a[i];
        }
        max_sum = max(max_sum, cur);
    }
    cout << max_sum << "\n";
    return 0;
}
