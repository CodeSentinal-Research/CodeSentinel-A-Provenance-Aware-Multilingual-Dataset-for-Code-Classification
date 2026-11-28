Here is the C++ code for the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findSubsets(vector<int> &nums, int start, int sum, vector<int> &current, vector<vector<int>> &result) {
    if(start == nums.size()) {
        if(sum == 0) {
            result.push_back(current);
        }
        return;
    }
    
    current.push_back(nums[start]);
    findSubsets(nums, start + 1, sum + nums[start], current, result);
    
    current.pop_back();
    findSubsets(nums, start + 1, sum, current, result);
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;
    
    findSubsets(nums, 0, 0, current, result);
    
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = subsets(nums);
    
    for(auto &subset : result) {
        for(int &num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}

In this code, we use a recursive function `findSubsets` to generate all the subsets. We pass the current subset and the index of the current number. If the current subset sum is zero (which means we have found a valid subset), we add the subset to the result.

If the current subset sum is not zero, we include the current number in the current subset and call the function again. If the current subset sum is zero, we exclude the current number from the current subset and call the function again.

In the `subsets` function, we call the `findSubsets` function and then sort the result in non-decreasing order.

In the `main` function, we call the `subsets` function and print all the subset sums in non-decreasing order.