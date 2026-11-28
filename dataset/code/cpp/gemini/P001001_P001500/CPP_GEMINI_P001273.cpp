#include <vector>
#include <unordered_map>
#include <queue>

class Solution {
public:
    std::vector<int> rearrangeBarcodes(std::vector<int>& barcodes) {
        std::unordered_map<int, int> count;
        for (int b : barcodes) count[b]++;

        std::priority_queue<std::pair<int, int>> pq;
        for (auto& [val, cnt] : count) pq.push({cnt, val});

        std::vector<int> res(barcodes.size());
        size_t idx = 0;

        while (!pq.empty()) {
            auto [cnt, val] = pq.top();
            pq.pop();
            while (cnt-- > 0) {
                res[idx] = val;
                idx += 2;
                if (idx >= barcodes.size()) idx = 1;
            }
        }
        return res;
    }
};