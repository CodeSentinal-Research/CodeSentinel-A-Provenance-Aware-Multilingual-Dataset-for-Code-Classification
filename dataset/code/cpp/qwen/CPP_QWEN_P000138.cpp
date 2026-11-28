#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> res;
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            res.push_back(a[i++]);
        } else {
            res.push_back(b[j++]);
        }
    }
    while (i < m) res.push_back(a[i++]);
    while (j < n) res.push_back(b[j++]);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }
    return 0;
}
