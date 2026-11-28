#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> count;
        for (int n : nums1) count[n]++;

        std::vector<int> res;
        for (int n : nums2) {
            if (count[n] > 0) {
                res.push_back(n);
                count[n]--;
            }
        }
        return res;
    }
};