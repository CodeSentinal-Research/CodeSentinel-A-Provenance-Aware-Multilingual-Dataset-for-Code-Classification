#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> countDistinct(std::vector<int>& arr, int k) {
        std::vector<int> res;
        std::unordered_map<int, int> freq;
        int distinct = 0;

        for (int i = 0; i < k; i++) {
            if (++freq[arr[i]] == 1) distinct++;
        }
        res.push_back(distinct);

        for (size_t i = k; i < arr.size(); i++) {
            if (--freq[arr[i - k]] == 0) distinct--;
            if (++freq[arr[i]] == 1) distinct++;
            res.push_back(distinct);
        }
        return res;
    }
};