#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        std::vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        std::priority_queue<std::pair<int, char>> pq;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) pq.push({count[i], (char)('a' + i)});
        }

        std::string res = "";
        std::pair<int, char> prev = {0, '#'};

        while (!pq.empty()) {
            auto [cnt, c] = pq.top();
            pq.pop();
            res += c;
            cnt--;

            if (prev.first > 0) pq.push(prev);
            prev = {cnt, c};
        }

        return res.length() == s.length() ? res : "";
    }
};