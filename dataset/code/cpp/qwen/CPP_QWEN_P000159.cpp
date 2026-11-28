#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long min_sum = LLONG_MAX, cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        min_sum = min(min_sum, cur);
        if (cur > 0) {
            cur = 0;
        }
    }
    cout << min_sum << "\n";
    return 0;
}
