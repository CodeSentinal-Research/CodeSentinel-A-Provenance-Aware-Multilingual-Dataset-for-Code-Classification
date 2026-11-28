#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
int main() {
    int d;
    if (std::cin >> d) {
        std::unordered_set<std::string> deadends;
        for (int i = 0; i < d; i++) {
            std::string s; std::cin >> s;
            deadends.insert(s);
        }
        std::string target;
        std::cin >> target;
        if (deadends.count("0000")) { std::cout << -1 << std::endl; return 0; }
        if (target == "0000") { std::cout << 0 << std::endl; return 0; }
        std::queue<std::pair<std::string, int>> q;
        q.push({"0000", 0});
        deadends.insert("0000");
        int ans = -1;
        while (!q.empty()) {
            auto [cur, dist] = q.front(); q.pop();
            if (cur == target) { ans = dist; break; }
            for (int i = 0; i < 4; i++) {
                for (int diff : {-1, 1}) {
                    std::string nxt = cur;
                    nxt[i] = (nxt[i] - '0' + diff + 10) % 10 + '0';
                    if (!deadends.count(nxt)) {
                        deadends.insert(nxt);
                        q.push({nxt, dist + 1});
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}