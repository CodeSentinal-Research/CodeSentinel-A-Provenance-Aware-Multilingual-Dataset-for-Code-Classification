#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        std::unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        std::priority_queue<std::pair<int, char>> pq;
        for (const auto& [c, f] : counts) {
            if (f > (int)(s.length() + 1) / 2) return "";
            pq.push({f, c});
        }
        std::string res = "";
        while (pq.size() >= 2) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();
            res += c1;
            res += c2;
            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }
        if (!pq.empty()) res += pq.top().second;
        return res;
    }
};