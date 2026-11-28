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
    int left = 0, right = n - 1;
    while (left < right) {
        maxPairSum = max(maxPairSum, nums[left] + nums[right]);
        left++;
        right--;
    }
    
    cout << maxPairSum << endl;
    return 0;
}
