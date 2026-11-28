Here is the C++ code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;
    int sum = 0, res = 0;
    for (int num : nums) {
        sum += num;
        sum %= k;
        if (sum < 0) sum += k;
        res += mp[sum];
        mp[sum]++;
    }
    return res;
}

int main() {
    vector<int> nums = {4, 3, 4, 1, 5, 2, 3, 5, 1};
    int k = 5;
    cout << countSubarrays(nums, k);
    return 0;
}

This code uses the concept of the prefix sum and the principle of hash map to solve the problem. The prefix sum is used to calculate the remainder when the sum is divided by k. The hash map is used to store the frequency of the remainder and the number of subarrays ending at the current index with the same remainder.