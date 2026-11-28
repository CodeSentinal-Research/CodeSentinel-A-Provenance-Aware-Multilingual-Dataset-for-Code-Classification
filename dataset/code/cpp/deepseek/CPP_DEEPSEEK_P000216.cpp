Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int minSubarray(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum == 0) return i + 1;
        if (mp.find(sum) != mp.end()) {
            return min(i - mp[sum], i - mp[sum] + 1);
        }
        mp[sum] = i;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minSubarray(nums);

    return 0;
}

In this code, we use an unordered map (`mp`) to store the prefix sum and its index. When we find a sum (`sum`) that is already in the map, we check if the current index (`i`) is smaller than the previous index in the map (`mp[sum]`). If it is, we return the shortest subarray length found so far. If not, we simply return the length difference between the previous and current index in the map (`i - mp[sum]`).

This solution assumes that the entire array has the same degree (the sum of all elements is zero). If the entire array does not have the same degree, we may need to modify the code to find the smallest contiguous subarray with the same sum.