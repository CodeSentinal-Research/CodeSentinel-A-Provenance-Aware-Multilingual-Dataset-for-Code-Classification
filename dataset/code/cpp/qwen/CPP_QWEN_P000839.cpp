#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isValidDivisor(const vector<int>& nums, int threshold, int divisor) {
    long long sum = 0;
    for (int num : nums) {
        sum += ceil((double)num / divisor);
    }
    return sum <= threshold;
}

int main() {
    int n, threshold;
    cin >> n >> threshold;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int low = 1;
    int high = *max_element(nums.begin(), nums.end());
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (isValidDivisor(nums, threshold, mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}
