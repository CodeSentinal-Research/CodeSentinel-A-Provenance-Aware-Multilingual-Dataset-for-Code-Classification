Here is the C++ code to solve the problem:

#include <iostream>
#include <vector>

int pivotIndex(std::vector<int>& nums) {
    int totalSum = 0;
    int leftSum = 0;

    for(int num : nums) {
        totalSum += num;
    }

    for(int i = 0; i < nums.size(); i++) {
        totalSum -= nums[i];
        if(leftSum == totalSum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    std::vector<int> nums = {1, 7, 3, 6, 5, 6, 2, 4};
    std::cout << pivotIndex(nums) << std::endl;
    return 0;
}

This code calculates the sum of all numbers in the array and then iterates through the array. It keeps track of the sum of the left side of the array and the current number, and if the left sum equals the total sum minus the current number, it means the current number is the pivot index. If no pivot index is found, it returns -1.