#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
int main() {
    int n;
    if (std::cin >> n) {
        std::unordered_map<int, int> count;
        std::queue<int> q;
        for (int i = 0; i < n; i++) {
            int v; std::cin >> v;
            count[v]++;
            q.push(v);
        }
        int q_count;
        std::cin >> q_count;
        while (q_count--) {
            std::string cmd;
            std::cin >> cmd;
            if (cmd == "showFirstUnique") {
                while (!q.empty() && count[q.front()] > 1) q.pop();
                std::cout << (q.empty() ? -1 : q.front()) << std::endl;
            } else if (cmd == "add") {
                int val; std::cin >> val;
                count[val]++;
                q.push(val);
            }
        }
    }
    return 0;
}