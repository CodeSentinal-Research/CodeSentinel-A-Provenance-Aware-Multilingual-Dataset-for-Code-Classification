#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    unordered_map<int, int> order;
    for (int i = 0; i < n; i++) order[b[i]] = i;
    sort(a.begin(), a.end(), [&](int x, int y) {
        if (order.count(x) && order.count(y)) return order[x] < order[y];
        if (order.count(x)) return true;
        if (order.count(y)) return false;
        return x < y;
    });
    for (int i = 0; i < m; i++) {
        cout << a[i] << (i == m - 1 ? "\n" : " ");
    }
    return 0;
}
