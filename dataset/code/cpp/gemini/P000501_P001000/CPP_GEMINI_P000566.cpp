#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
int main() {
    std::string start_gene, end_gene;
    int n;
    if (std::cin >> start_gene >> end_gene >> n) {
        std::unordered_set<std::string> bank;
        for (int i = 0; i < n; i++) {
            std::string s; std::cin >> s;
            bank.insert(s);
        }
        if (!bank.count(end_gene)) { std::cout << -1 << std::endl; return 0; }
        std::queue<std::pair<std::string, int>> q;
        q.push({start_gene, 0});
        std::unordered_set<std::string> vis = {start_gene};
        int ans = -1;
        while (!q.empty()) {
            auto [gene, step] = q.front(); q.pop();
            if (gene == end_gene) { ans = step; break; }
            for (int i = 0; i < 8; i++) {
                std::string nxt = gene;
                for (char c : {'A', 'C', 'G', 'T'}) {
                    nxt[i] = c;
                    if (bank.count(nxt) && !vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push({nxt, step + 1});
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}