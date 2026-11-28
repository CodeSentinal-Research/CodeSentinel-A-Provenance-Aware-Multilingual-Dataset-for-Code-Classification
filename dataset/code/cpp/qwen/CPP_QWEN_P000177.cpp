#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, target;
    cin >> n >> k >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    while (r - l + 1 > k) {
        if (abs(a[l] - target) > abs(a[r] - target)) {
            l++;
        } else {
            r--;
        }
    }
    for (int i = l; i <= r; i++) {
        cout << a[i] << (i == r ? "\n" : " ");
    }
    return 0;
}
