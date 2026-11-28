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
    int l = 0, r = n - 1;
    bool found = false;
    while (l < r) {
        int sum = a[l] + a[r];
        if (sum == target) {
            cout << a[l] << " " << a[r] << "\n";
            l++;
            r--;
            found = true;
        } else if (sum < target) {
            l++;
        } else {
            r--;
        }
    }
    if (!found) cout << "\n";
    return 0;
}
