#include <vector>

class Solution {
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) {
        std::vector<int> prefix(arr.size() + 1, 0);
        for (size_t i = 0; i < arr.size(); i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        std::vector<int> res;
        res.reserve(queries.size());
        for (const auto& q : queries) {
            res.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
        }
        return res;
    }
};