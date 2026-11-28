#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int closest = a[0] + a[1] + a[2];
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = a[i] + a[l] + a[r];
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }
            if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << closest << "\n";
    return 0;
}
