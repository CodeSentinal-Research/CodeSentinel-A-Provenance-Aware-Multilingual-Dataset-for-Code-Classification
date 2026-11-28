#include <iostream>
#include <vector>
#include <deque>

using namespace std;

double maxAverageSubarray(vector<int>& nums, int k) {
    double sum = 0;
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        sum += nums[i];
        dq.push_back(nums[i]);
    }

    double maxSum = sum;
    for (int i = k; i < nums.size(); i++) {
        sum += nums[i] - dq.front();
        dq.pop_front();
        dq.push_back(nums[i]);
        maxSum = max(maxSum, sum);
    }

    return maxSum / k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << maxAverageSubarray(nums, k);

    return 0;
}