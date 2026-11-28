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
    
    long long minSum = windowSum;
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        minSum = min(minSum, windowSum);
    }
    
    cout << minSum << endl;
    return 0;
}
