Here's the code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minProduct(vector<int>& nums) {
    int n = nums.size();
    long long min1 = LLONG_MAX, min2 = LLONG_MAX, max1 = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if (nums[i] < min2) {
            min2 = nums[i];
        }
        if (nums[i] > max1) {
            max1 = nums[i];
        }
    }
    return min(min1 * min2, max1);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << minProduct(nums) << endl;
    return 0;
}
This program first reads the size of the array from the input. Then, it reads the array from the input. The `minProduct` function finds the minimum product of any contiguous subarray. The `main` function reads the input and prints the result.