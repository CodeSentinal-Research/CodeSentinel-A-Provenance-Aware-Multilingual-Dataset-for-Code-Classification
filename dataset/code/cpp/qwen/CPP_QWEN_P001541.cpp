#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += nums[i];
    
    long long maxSum = windowSum;
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        maxSum = max(maxSum, windowSum);
    }
    
    cout << maxSum << endl;
    return 0;
}
