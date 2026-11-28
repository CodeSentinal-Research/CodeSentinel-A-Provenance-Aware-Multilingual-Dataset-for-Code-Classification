#include <vector>
#include <deque>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::deque<int> maxDq, minDq;
        int l = 0;

        for (int num : nums) {
            while (!maxDq.empty() && num > maxDq.back()) maxDq.pop_back();
            while (!minDq.empty() && num < minDq.back()) minDq.pop_back();
            maxDq.push_back(num);
            minDq.push_back(num);

            if (maxDq.front() - minDq.front() > limit) {
                if (maxDq.front() == nums[l]) maxDq.pop_front();
                if (minDq.front() == nums[l]) minDq.pop_front();
                l++;
            }
        }
        return nums.size() - l;
    }
};