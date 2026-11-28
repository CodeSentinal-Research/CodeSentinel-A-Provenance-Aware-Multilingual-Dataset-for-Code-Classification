#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxWidthRamp(vector<int>& nums) {
    stack<int> s;
    int n = nums.size();
    for(int i=0; i<n; ++i) {
        if(s.empty() || nums[i] < nums[s.top()]) {
            s.push(i);
        }
    }
    int maxWidth = 0;
    for(int i=n-1; i>=0; --i) {
        while(!s.empty() && nums[i] >= nums[s.top()]) {
            maxWidth = max(maxWidth, i - s.top());
            s.pop();
        }
    }
    return maxWidth;
}

int main() {
    vector<int> nums = {6, 5, 5, 3, 2, 6};
    cout << maxWidthRamp(nums) << endl;
    return 0;
}
This C++ solution uses a stack to keep track of the indices of the numbers that are smaller than the current number. The stack is used to find the largest ramp in the array. The ramp is defined as a pair of indices (i, j) such that i < j and nums[i] <= nums[j]. The algorithm loops through the array from left to right, pushing the indices of the numbers that are smaller than the current number to the stack. In the end, the algorithm loops through the array again from right to left, and for each number, it pops the indices of the numbers that are larger or equal to the current number from the stack until it finds a number that is smaller. The maximum width is updated as the maximum between the current width and the width found so far.