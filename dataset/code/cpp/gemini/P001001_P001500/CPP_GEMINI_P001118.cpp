#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::string alienOrder(std::vector<std::string>& words) {
        std::unordered_map<char, std::unordered_set<char>> adj;
        std::unordered_map<char, int> inDeg;
        for (const auto& w : words) {
            for (char c : w) {
                inDeg[c] = 0;
                adj[c];
            }
        }
        for (size_t i = 0; i < words.size() - 1; i++) {
            const auto& w1 = words[i];
            const auto& w2 = words[i + 1];
            size_t minLen = std::min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.compare(0, minLen, w2, 0, minLen) == 0) return "";
            for (size_t j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        inDeg[w2[j]]++;
                    }
                    break;
                }
            }
        }
        std::queue<char> q;
        for (const auto& [c, deg] : inDeg) {
            if (deg == 0) q.push(c);
        }
        std::string res = "";
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            res += c;
            for (char nxt : adj[c]) {
                if (--inDeg[nxt] == 0) q.push(nxt);
            }
        }
        return res.length() == inDeg.size() ? res : "";
    }
};