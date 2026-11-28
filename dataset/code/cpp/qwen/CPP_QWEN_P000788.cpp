#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    double windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += nums[i];
    
    double maxAvg = windowSum / k;
    for (int i = k; i < n; ++i) {
        windowSum += nums[i] - nums[i-k];
        maxAvg = max(maxAvg, windowSum / k);
    }
    
    cout << maxAvg << endl;
    return 0;
}
