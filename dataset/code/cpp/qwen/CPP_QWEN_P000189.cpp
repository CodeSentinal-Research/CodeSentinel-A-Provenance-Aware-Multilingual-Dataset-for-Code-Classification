#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long total = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    long long max_kadane = LLONG_MIN, min_kadane = LLONG_MAX;
    long long cur_max = 0, cur_min = 0;
    for (int i = 0; i < n; i++) {
        cur_max += a[i];
        max_kadane = max(max_kadane, cur_max);
        if (cur_max < 0) cur_max = 0;
        cur_min += a[i];
        min_kadane = min(min_kadane, cur_min);
        if (cur_min > 0) cur_min = 0;
    }
    long long res = max_kadane;
    if (total != min_kadane) res = max(res, total - min_kadane);
    cout << res << "\n";
    return 0;
}
