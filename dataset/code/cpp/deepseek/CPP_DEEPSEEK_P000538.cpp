#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    int res = n + 1;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        if (sum >= k) {
            res = min(res, i + 1);
        }
        while (!dq.empty() && sum - dq.front() >= k) {
            sum -= dq.front();
            dq.pop_front();
            if (res > i - dq.front()) {
                res = i - dq.front();
            }
        }
        if (sum >= k) {
            dq.clear();
        }
        dq.push_back(i);
    }
    if (res == n + 1) {
        return -1;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 10;
    cout << shortestSubarray(nums, k);
    return 0;
}
In this code, the function `shortestSubarray` calculates the sum of the subarray from index 0 to i (inclusive) and updates the result if the sum is greater than or equal to k. The function then checks if the sum can be reduced further by subtracting the smallest element from the front of the deque. If the sum is greater than or equal to k, it removes the smallest element from the front of the deque. If the result is greater than i - front of the deque, it updates the result. The process repeats until the sum is less than k. If no valid subarray exists, it returns -1.