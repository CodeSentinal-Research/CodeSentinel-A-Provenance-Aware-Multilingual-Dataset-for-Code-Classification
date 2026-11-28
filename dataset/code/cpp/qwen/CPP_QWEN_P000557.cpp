#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int target;
    cin >> target;
    queue<pair<long long, long long>> q; // pos, speed
    q.push({0, 1});
    unordered_set<string> vis;
    vis.insert("0,1");
    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            auto [pos, speed] = q.front(); q.pop();
            if (pos == target) {
                cout << steps << endl;
                return 0;
            }
            // Accelerate
            string key1 = to_string(pos + speed) + "," + to_string(speed * 2);
            if (abs(pos + speed) <= 2 * target && vis.find(key1) == vis.end()) {
                vis.insert(key1);
                q.push({pos + speed, speed * 2});
            }
            // Reverse
            long long new_speed = (speed > 0) ? -1 : 1;
            string key2 = to_string(pos) + "," + to_string(new_speed);
            if (vis.find(key2) == vis.end()) {
                vis.insert(key2);
                q.push({pos, new_speed});
            }
        }
        steps++;
    }
    cout << -1 << endl;
    return 0;
}
