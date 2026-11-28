#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
    result.push_back(current);
    for(int i = start; i < nums.size(); i++) {
        if(i > start && nums[i] == nums[i-1]) continue;
        current.push_back(nums[i]);
        printSubsets(nums, result, current, i+1);
        current.pop_back();
    }
}

int main() {
    vector<int> nums = {1,2,2};
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    printSubsets(nums, result, current, 0);
    for(auto& subset : result) {
        for(int& num : subset) {
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}