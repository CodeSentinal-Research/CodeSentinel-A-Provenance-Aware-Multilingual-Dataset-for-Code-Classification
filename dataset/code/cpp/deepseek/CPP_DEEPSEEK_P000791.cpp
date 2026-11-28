#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int n = nums.size();
    int sum = 0;
    int maxLen = 0;
    
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }
        
        if (map.find(sum - k) != map.end()) {
            maxLen = max(maxLen, i - map[sum - k]);
        }
        
        if (map.find(sum + k) == map.end()) {
            map[sum + k] = i;
        }
    }
    
    return maxLen;
}

int main() {
    vector<int> nums = {1, 1, 1, 1};
    int k = 2;
    cout << longestSubarray(nums, k);
    return 0;
}