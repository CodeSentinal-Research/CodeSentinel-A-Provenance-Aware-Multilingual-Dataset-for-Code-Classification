#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canFormPairs(const vector<int>& nums, int p, int maxDiff) {
    int pairs = 0;
    int i = 0;
    while (i < nums.size() - 1) {
        if (nums[i+1] - nums[i] <= maxDiff) {
            pairs++;
            i += 2;
        } else {
            i++;
        }
    }
    return pairs >= p;
}

int main() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    int low = 0;
    int high = nums.back() - nums.front();
    int ans = 0;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canFormPairs(nums, p, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
