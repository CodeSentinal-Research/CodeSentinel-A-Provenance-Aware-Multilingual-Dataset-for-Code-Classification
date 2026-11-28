#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long min_prod = min((long long)a[0] * a[1], (long long)a[n - 1] * a[n - 2]);
    cout << min_prod << "\n";
    return 0;
}
