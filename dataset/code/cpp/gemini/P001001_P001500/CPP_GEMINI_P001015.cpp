#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> count;
        for (int x : nums) count[x]++;
        auto comp = [&](int a, int b) { return count[a] > count[b]; };
        std::priority_queue<int, std::vector<int>, decltype(comp)> pq(comp);
        for (const auto& [val, _] : count) {
            pq.push(val);
            if ((int)pq.size() > k) pq.pop();
        }
        std::vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};