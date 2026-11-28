#include <vector>
#include <algorithm>

class Solution {
    std::vector<int> maxSingle(const std::vector<int>& nums, int k) {
        std::vector<int> stack;
        int drop = nums.size() - k;
        for (int x : nums) {
            while (drop > 0 && !stack.empty() && stack.back() < x) {
                stack.pop_back();
                drop--;
            }
            stack.push_back(x);
        }
        stack.resize(k);
        return stack;
    }

    std::vector<int> merge(std::vector<int> a, std::vector<int> b, int k) {
        std::vector<int> res;
        auto p1 = a.begin(), p2 = b.begin();
        while (p1 != a.end() || p2 != b.end()) {
            if (std::lexicographical_compare(p1, a.end(), p2, b.end())) {
                res.push_back(*p2++);
            } else {
                res.push_back(*p1++);
            }
        }
        return res;
    }
public:
    std::vector<int> maxNumber(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        std::vector<int> maxArr;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = std::max(0, k - n2); i <= std::min(k, n1); i++) {
            auto cand = merge(maxSingle(nums1, i), maxSingle(nums2, k - i), k);
            maxArr = std::max(maxArr, cand);
        }
        return maxArr;
    }
};