#include <iostream>
#include <vector>

int findMissingNumber(std::vector<int>& nums) {
    int missing = nums.size()+1; 
    int xor = 1;

    for (int i = 0; i < nums.size(); i++) {
        xor ^= nums[i];
    }

    for (int i = 1; i <= nums.size()+1; i++) {
        xor ^= i;
    }

    return xor;
}

int main() {
    std::vector<int> nums = {1, 5, 2, 6, 3, 7, 4};
    std::cout << findMissingNumber(nums) << std::endl;
    return 0;
}

This code first calculates the XOR of all numbers from 1 to n+1. This will be the XOR of the array numbers and the numbers from 1 to n+1. Then it again calculates the XOR of all numbers in the array and this XOR will be the missing number.