Here is the C++ code that handles the problem:

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarrays(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    int prefixSum = 0;
    for (int i = 0; i < n; i++) {
        prefixSum += nums[i];
        if (mp.find(prefixSum) != mp.end()) {
            ans += mp[prefixSum]++;
        } else {
            mp[prefixSum] = 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {0,1,2,1,3,4,5,0,1,2,1,3,4,5,0,1,2,1,3,4,5,0,1,2,1,3,4,5};
    cout << countSubarrays(nums) << endl;
    return 0;
}
This code works by using a prefix sum approach. The prefix sum is the sum of all elements from the start of the array to the current element. If the prefix sum has appeared before, it means we have found a subarray with an equal number of 0s and 1s, so we increment the count by the number of times the prefix sum has appeared before. If the prefix sum has not appeared before, we store it into the hash map for future use.