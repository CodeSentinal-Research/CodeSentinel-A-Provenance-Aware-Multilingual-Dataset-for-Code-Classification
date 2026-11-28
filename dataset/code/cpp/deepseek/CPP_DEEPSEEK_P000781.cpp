#include <iostream>
#include <vector>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    for(int i = 1; i < nums.size(); i++) {
        nums[i] += nums[i - 1];
    }
    return nums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    nums = runningSum(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    return 0;
}