#include <vector>

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> res;
        res.reserve(encoded.size() + 1);
        res.push_back(first);
        for (int x : encoded) {
            res.push_back(res.back() ^ x);
        }
        return res;
    }
};