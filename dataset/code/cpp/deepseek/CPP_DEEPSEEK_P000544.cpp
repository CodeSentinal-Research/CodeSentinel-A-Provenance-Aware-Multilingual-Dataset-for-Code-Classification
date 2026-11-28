#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> deadSet(deadends.begin(), deadends.end());
    if (deadSet.count("0000")) return -1; 

    queue<pair<string, int>> q;
    q.push({"0000", 0});

    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();

        if (cur == target) return step;
        if (deadSet.count(cur)) continue;

        for (int i = 0; i < 4; i++) {
            for (int dir : {-1, 1}) {
                string next = cur;
                next[i] += dir;
                if (next < "0000" || next > "9999") continue;
                if (deadSet.count(next)) continue;
                q.push({next, step + 1});
            }
        }
    }

    return -1; 
}

int main() {
    vector<string> deadends = {"0000"};
    string target = "8888";
    cout << openLock(deadends, target);
    return 0;
}