#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int solve(vector<string>& deadends, string target) {
    unordered_set<string> dead(deadends.begin(), deadends.end());
    if (dead.count("0000")) return -1;
    queue<pair<string, int>> q;
    q.push({"0000", 0}); dead.insert("0000");
    while (!q.empty()) {
        auto [curr, steps] = q.front(); q.pop();
        if (curr == target) return steps;
        for (int i = 0; i < 4; i++) {
            for (int d = -1; d <= 1; d += 2) {
                string next = curr;
                next[i] = (next[i] - '0' + d + 10) % 10 + '0';
                if (!dead.count(next)) { dead.insert(next); q.push({next, steps + 1}); }
            }
        }
    }
    return -1;
}

int main() {
    int d; cin >> d;
    vector<string> dead(d);
    for(int i = 0; i < d; i++) cin >> dead[i];
    string target; cin >> target;
    cout << solve(dead, target) << endl;
    return 0;
}
