#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
    std::unordered_map<std::string, std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>> map;
    std::vector<std::string> res;

    void dfs(const std::string& curr) {
        auto& pq = map[curr];
        while (!pq.empty()) {
            std::string nxt = pq.top();
            pq.pop();
            dfs(nxt);
        }
        res.push_back(curr);
    }
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        for (const auto& t : tickets) {
            map[t[0]].push(t[1]);
        }
        dfs("JFK");
        std::reverse(res.begin(), res.end());
        return res;
    }
};