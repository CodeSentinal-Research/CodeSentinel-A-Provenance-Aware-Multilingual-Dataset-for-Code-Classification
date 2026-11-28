#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int sum = 0;
    int minLength = INT_MAX;

    while (right < nums.size()) {
        sum += nums[right];

        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }

        right++;
    }

    return minLength == INT_MAX ? 0 : minLength;
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << minSubArrayLen(target, nums) << endl;

    return 0;
}