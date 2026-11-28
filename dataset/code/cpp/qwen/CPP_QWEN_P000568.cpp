#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    x = abs(x); y = abs(y);
    queue<pair<int, int>> q;
    q.push({0, 0});
    unordered_set<string> vis;
    vis.insert("0,0");
    int moves = 0;
    // Optimization: symmetry and bounds
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [r, c] = q.front(); q.pop();
            if (r == x && c == y) {
                cout << moves << endl;
                return 0;
            }
            vector<pair<int, int>> next = {{r+2,c+1},{r+2,c-1},{r-2,c+1},{r-2,c-1},
                                           {r+1,c+2},{r+1,c-2},{r-1,c+2},{r-1,c-2}};
            for (auto [nr, nc] : next) {
                string key = to_string(nr) + "," + to_string(nc);
                if (abs(nr) <= x + 2 && abs(nc) <= y + 2 && vis.find(key) == vis.end()) {
                    vis.insert(key);
                    q.push({nr, nc});
                }
            }
        }
        moves++;
    }
    cout << -1 << endl;
    return 0;
}
