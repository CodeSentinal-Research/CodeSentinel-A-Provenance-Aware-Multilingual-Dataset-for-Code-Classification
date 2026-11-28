#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        std::sort(nums1.begin(), nums1.end());
        std::priority_queue<std::pair<int, int>> pq;
        for (int i = 0; i < n; i++) pq.push({nums2[i], i});

        int l = 0, r = n - 1;
        std::vector<int> res(n);

        while (!pq.empty()) {
            auto [val, idx] = pq.top();
            pq.pop();
            if (nums1[r] > val) {
                res[idx] = nums1[r--];
            } else {
                res[idx] = nums1[l++];
            }
        }
        return res;
    }
};