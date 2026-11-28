#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1, max_area = 0;
    while (l < r) {
        max_area = max(max_area, (r - l) * min(a[l], a[r]));
        if (a[l] < a[r]) {
            l++;
        } else {
            r--;
        }
    }
    cout << max_area << "\n";
    return 0;
}
