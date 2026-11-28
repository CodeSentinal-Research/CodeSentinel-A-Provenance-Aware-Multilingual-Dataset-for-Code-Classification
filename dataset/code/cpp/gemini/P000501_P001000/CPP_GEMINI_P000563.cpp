#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
int main() {
    std::string begin_word, end_word;
    int n;
    if (std::cin >> begin_word >> end_word >> n) {
        std::unordered_set<std::string> word_list;
        for (int i = 0; i < n; i++) {
            std::string w; std::cin >> w;
            word_list.insert(w);
        }
        if (!word_list.count(end_word)) { std::cout << 0 << std::endl; return 0; }
        std::queue<std::pair<std::string, int>> q;
        q.push({begin_word, 1});
        std::unordered_set<std::string> vis = {begin_word};
        int ans = 0;
        while (!q.empty()) {
            auto [word, len] = q.front(); q.pop();
            if (word == end_word) { ans = len; break; }
            for (size_t i = 0; i < word.length(); i++) {
                std::string nxt = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    nxt[i] = c;
                    if (word_list.count(nxt) && !vis.count(nxt)) {
                        vis.insert(nxt);
                        q.push({nxt, len + 1});
                    }
                }
            }
        }
        std::cout << ans << std::endl;
    }
    return 0;
}