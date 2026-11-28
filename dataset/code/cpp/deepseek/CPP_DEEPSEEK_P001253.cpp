#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int min_diff = nums[1] - nums[0];
    for (int i = 0; i < n - 1; i++) {
        if (nums[i+1] - nums[i] < min_diff) {
            min_diff = nums[i+1] - nums[i];
        }
    }
    cout << min_diff;
    return 0;
}