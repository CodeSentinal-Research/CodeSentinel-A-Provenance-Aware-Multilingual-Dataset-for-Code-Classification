#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int closest = nums[0] + nums[1] + nums[2];
    int absDiff = abs(closest - target);

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {
        int start = i + 1;
        int end = n - 1;

        while (start < end) {
            int sum = nums[i] + nums[start] + nums[end];
            int absSum = abs(sum - target);

            if (absSum == 0) {
                return sum;
            }

            if (absSum < absDiff) {
                closest = sum;
                absDiff = absSum;
            }

            if (sum > target) {
                end--;
            } else {
                start++;
           
            }
        }
    }

    return closest;
}

int main() {
    int n, target;

    cin >> n >> target;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << threeSumClosest(nums, target);

    return 0;
}