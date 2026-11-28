#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    sort(nums.begin(), nums.end());
    
    int maxPairSum = 0;
    for (int i = 0; i < n / 2; ++i) {
        maxPairSum = max(maxPairSum, nums[i] + nums[n - 1 - i]);
    }
    
    cout << maxPairSum << endl;
    return 0;
}
