Here is a simple C++ solution for the given problem:

#include <iostream>
#include <vector>

using namespace std;

void solve(int n, vector<int>& nums) {
    int leftSum = 0, rightSum = 0;
    for(int i=0; i<n; i++) {
        rightSum += nums[i];
        nums[i] = abs(leftSum - rightSum);
        leftSum += nums[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }
    solve(n, nums);
    for(int i=0; i<n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}

In this code, we first calculate the sum of all the elements in the array and store it in `rightSum`. Then, we iterate over the array, and for each element, we calculate the absolute difference between the sum of the elements to its left and the current element (which is the sum of the elements to the right minus the sum of the elements to the left). We then store this difference in the current element of the array. Finally, we print the resulting array.