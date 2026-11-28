// Find the Missing and Repeating Number
// Example: Input: n = 5, arr[] = {1, 3, 3, 5, 4}
// Output: Missing = 2, Repeating = 3

#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1, 3, 3, 5, 4};
    int n = nums.size();
    int missing = -1, repeating = -1;
    for (int i = 0; i < n; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            repeating = abs(nums[i]);
        } else {
            nums[index] = -nums[index];
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            missing = i + 1;
            break;
        }
    }
    cout << "Missing = " << missing << ", Repeating = " << repeating << endl;
    return 0;
}