Here is the code snippet:

#include <iostream>
#include <unordered_map>
#include <vector>

int solve(std::vector<int>& nums) {
    std::unordered_map<int, int> sumMap;
    int sum = 0;
    int maxLength = 0;
    
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        
        if (sum == 0) {
            maxLength = i + 1;
        } else {
            if (sumMap.find(sum) != sumMap.end()) {
                if (maxLength < i - sumMap[sum]) {
                    maxLength = i - sumMap[sum];
                }
            } else {
                sumMap[sum] = i;
            }
        }
    }
    
    return maxLength;
}

int main() {
    std::vector<int> nums = {1, -2, 3, 1};
    std::cout << solve(nums) << std::endl;
    return 0;
}

This code uses a hash map to record the sum of elements up to each index. It iterates through the array, accumulating the sum and updating the longest valid subarray length when the sum is zero. If the sum is not found in the hash map, it adds the sum and index to the hash map. If the sum is found, it checks if the current subarray length is longer than the previous one.