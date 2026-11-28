#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long sum = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (sum > target) {
            sum -= a[l++];
        }
        if (sum == target) {
            cout << l + 1 << " " << r + 1 << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}
