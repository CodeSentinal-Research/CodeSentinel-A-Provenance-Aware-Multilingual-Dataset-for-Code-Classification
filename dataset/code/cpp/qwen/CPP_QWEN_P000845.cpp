#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canRob(const vector<int>& nums, int k, int capability) {
    int robbed = 0;
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] <= capability) {
            robbed++;
            i += 2; // Skip next as it's adjacent
        } else {
            i++;
        }
    }
    return robbed >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    int low = *min_element(nums.begin(), nums.end());
    int high = *max_element(nums.begin(), nums.end());
    int ans = high;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canRob(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
