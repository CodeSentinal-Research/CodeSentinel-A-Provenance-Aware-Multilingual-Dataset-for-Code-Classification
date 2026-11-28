#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main() {
    int n, p, b, k;
    cin >> n >> p >> b >> k;
    vector<int> banned(b);
    for (int i = 0; i < b; i++) cin >> banned[i];
    set<int> ban(banned.begin(), banned.end());
    vector<int> res(n, -1);
    if (ban.count(p)) {
        for (int i = 0; i < n; i++) cout << -1 << " ";
        cout << endl;
        return 0;
    }
    queue<int> q;
    q.push(p);
    res[p] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v = max(0, u - k + 1); v <= min(n - 1, u + k - 1); v++) {
            if (!ban.count(v) && res[v] == -1) {
                res[v] = res[u] + 1;
                q.push(v);
            }
        }
    }
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}
