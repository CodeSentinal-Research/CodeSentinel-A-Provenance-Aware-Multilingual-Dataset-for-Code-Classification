#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(int N, vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    int sum1 = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < N / 2; ++i) {
        sum1 += nums[i];
    }

    int sum2 = totalSum - sum1;

    return abs(sum1 - sum2);
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int minDiff = partition(N, nums);

    cout << minDiff;

    return 0;
}