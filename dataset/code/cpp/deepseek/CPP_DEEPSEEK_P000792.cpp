Here is the C++ code that fulfills the problem:

#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& nums, int goal) {
    int n = nums.size();
    int i = 0, j = 1, count = 0;
    while(i < n && j < n){
        if(nums[i] + nums[j] == goal){
            count++;
            i++;
            j++;
        }else if(nums[i] + nums[j] < goal){
            i++;
        }else{
            j++;
        }
    }
    return count;
}

int main() {
    vector<int> nums = {1,2,3,4};
    int goal = 3;
    cout << countSubarrays(nums, goal);
    return 0;
}

In this code, two pointers `i` and `j` are used to traverse the array. If the sum of the elements at `i` and `j` is equal to `goal`, the count is incremented, and both `i` and `j` are moved one step forward. If the sum is less than `goal`, `i` is moved one step forward. If the sum is more than `goal`, `j` is moved one step forward. This continues until all possible subarrays have been checked.