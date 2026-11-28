#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> prefix;
    long long sum = 0;
    int max_len = 0;
    prefix[0] = -1;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (prefix.count(sum - k)) {
            max_len = max(max_len, i - prefix[sum - k]);
        }
        if (!prefix.count(sum)) prefix[sum] = i;
    }
    cout << max_len << "\n";
    return 0;
}
