#include <iostream>
#include <unordered_map>
#include <vector>

int findMaxLength(std::vector<int>& nums) {
    std::unordered_map<int, int> map;
    int maxLength = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum == 0) {
            maxLength = i + 1 > maxLength ? i + 1 : maxLength;
        } else {
            if (map.find(sum) != map.end()) {
                maxLength = std::max(maxLength, i - map[sum]);
            } else {
                map[sum] = i;
            }
        }
    }
    return maxLength;
}

int main() {
    std::vector<int> nums = {0, 1, 0, 0, 1, 0, 1, 0, 1};
    std::cout << findMaxLength(nums) << std::endl;
    return 0;
}