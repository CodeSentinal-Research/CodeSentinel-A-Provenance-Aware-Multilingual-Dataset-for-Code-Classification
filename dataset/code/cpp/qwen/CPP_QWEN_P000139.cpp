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
    set<int> s1(a.begin(), a.end());
    set<int> s2(b.begin(), b.end());
    vector<int> res;
    for (int x : s1) {
        if (s2.count(x)) {
            res.push_back(x);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << (i == res.size() - 1 ? "\n" : " ");
    }
    return 0;
}
