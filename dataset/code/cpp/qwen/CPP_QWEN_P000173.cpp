#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int min_val = a[0], max_diff = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] - min_val > max_diff) {
            max_diff = a[i] - min_val;
        }
        if (a[i] < min_val) {
            min_val = a[i];
        }
    }
    cout << max_diff << "\n";
    return 0;
}
