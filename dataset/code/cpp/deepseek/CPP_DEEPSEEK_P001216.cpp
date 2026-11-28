#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long minCost(vector<long long> &nums, int start, int end) {
    if (start == end) {
        return 0;
    }

    long long ans = numeric_limits<long long>::max();
    for (int i = start; i < end; ++i) {
        long long cost = nums[i] * nums[end] * nums[start] +
                         minCost(nums, start, i) +
                         minCost(nums, i + 1, end);
        ans = min(ans, cost);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    cout << minCost(nums, 0, n - 1) << endl;

    return 0;
}