#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int minSubarray(vector<int>& nums, int p) {
    long long sum = accumulate(nums.begin(), nums.end(), 0LL);
    if (sum % p != 0) {
        return -1;
    }
    sum /= p;
    int minLen = nums.size() + 1;
    long long curSum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); ++i) {
        curSum += nums[i];
        if (curSum == sum) {
            minLen = min(minLen, i + 1);
            count++;
            curSum = 0;
        }
    }
    if (count == 0) {
        return -1;
    }
    return minLen;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 5, 2, 3, 1};
    int p = 4;
    cout << minSubarray(nums, p) << endl;
    return 0;
}
This C++ solution first checks if the sum of the array can be divided by p. If not, it returns -1. If it can, it divides the sum by p and then iterates over the array to find the smallest subarray that sums to the quotient. It keeps track of the count of non-empty subarrays and their lengths, and returns the smallest length found.