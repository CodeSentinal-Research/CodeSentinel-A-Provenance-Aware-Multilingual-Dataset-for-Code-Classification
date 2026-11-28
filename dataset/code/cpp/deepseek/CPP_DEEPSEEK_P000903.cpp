Here is the C++ code to solve the largest divisible subset problem. This code uses dynamic programming to find the largest divisible subset.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), idx(n);
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                idx[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }
    vector<int> answer;
    while (n != 0) {
        answer.push_back(nums[maxIndex]);
        maxIndex = idx[maxIndex];
        n--;
    }
    return answer;
}

int main() {
    vector<int> nums = {4, 8, 16, 18};
    vector<int> result = largestDivisibleSubset(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}

In this code, we initialize two arrays dp and idx. dp[i] represents the size of the largest divisible subset ending at index i, and idx[i] represents the previous index in the largest divisible subset ending at index i.

We iterate over the array and for each number, we check if the number divides the number we are checking for (i.e., nums[i] % nums[j] == 0), and if the current subset ending at i is smaller than the subset ending at j + 1 plus 1 (which means adding the current number to the subset ending at j will result in a larger subset). If so, we update the size of the current subset and the previous index.

Finally, we reconstruct the largest divisible subset and return it.