#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestWiggleSequence(vector<int> nums) {
    int n = nums.size();
    if (n < 2) {
        return n;
    }
    int prevDiff = nums[1] - nums[0];
    int maxLength = 2;
    int currLength = 2;
    for (int i = 2; i < n; i++) {
        int diff = nums[i] - nums[i - 1];
        if (diff == 0) {
            diff = prevDiff;
        }
        if (diff * prevDiff < 0) {
            currLength++;
            prevDiff = diff;
        } else {
            currLength = 2;
            prevDiff = diff;
        }
        maxLength = max(maxLength, currLength);
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << longestWiggleSequence(nums);
    return 0;
}
This C++ solution uses dynamic programming to solve the problem. It calculates the difference between each pair of consecutive numbers and keeps track of the maximum length of wiggle sequence encountered so far. If the difference between two consecutive numbers is 0, it means that we are backtracking to the previous pair, so it updates the difference to the previous difference. If the difference is positive or negative and the previous difference is also positive or negative, it means that we have a wiggle sequence, so it increments the current length and updates the previous difference. Otherwise, it resets the current length and previous difference to 2. The maximum length is updated with the current length.