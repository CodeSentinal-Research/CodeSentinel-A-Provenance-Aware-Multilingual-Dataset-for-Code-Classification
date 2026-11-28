Here is the C++ code for the given problem:

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int maxSum(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    long long sum = 0;

    for (int i = 0; i < k; i++) {
        sum += nums[i];
        dq.push_back(nums[i]);
    }

    for (int i = k; i < n; i++) {
        sum += nums[i] - dq.front();
        dq.pop_front();
        dq.push_back(nums[i]);
    }

    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxSum(nums, k);

    return 0;
}

This code firstly computes the sum of the first K elements in the array. Then it calculates the sum of remaining (N-K) elements by subtracting the first element of the current subarray and adding the next element. This is done by continuously popping the front element and adding the next element from the queue, and then pushing the next element onto the back. The maximum sum is then stored in the variable `sum` and returned.