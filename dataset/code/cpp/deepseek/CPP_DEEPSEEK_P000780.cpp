#include <iostream>
#include <vector>

using namespace std;

vector<int> prefixSum(vector<int>& nums) {
    vector<int> prefixSumArray(nums.size());
    
    prefixSumArray[0] = nums[0];
    
    for(int i = 1; i < nums.size(); i++) {
        prefixSumArray[i] = prefixSumArray[i-1] + nums[i];
    }
    
    return prefixSumArray;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> prefixSumArray = prefixSum(nums);

    for(int i = 0; i < prefixSumArray.size(); i++) {
        cout << prefixSumArray[i] << " ";
    }
    
    return 0;
}