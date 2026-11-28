Here is the complete C++ code for the problem:

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLengthSubarray(vector<int> nums) {
    unordered_map<int, int> map;
    int maxLen = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0) {
            sum += 2;
        } else {
            sum += 1;
        }
        if (map.find(sum) != map.end()) {
            maxLen = max(maxLen, i - map[sum]);
        } else {
            map[sum] = i;
        }
    }
    return maxLen;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << maxLengthSubarray(nums);
    return 0;
}

This code is designed to solve the problem. The program first calculates the sum of the even and odd numbers in the array. Then, it uses a hash map to store the sum and its corresponding index. If the sum already exists in the hash map, it calculates the maximum length of the subarray that can end at the current index. Otherwise, it stores the sum and its index in the hash map.