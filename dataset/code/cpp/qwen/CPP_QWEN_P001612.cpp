#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
    if (totalSum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    long long target = totalSum / 3;
    long long currentSum = 0;
    int countTarget = 0;
    long long ways = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        currentSum += nums[i];
        if (currentSum == 2 * target) {
            ways += countTarget;
        }
        if (currentSum == target) {
            countTarget++;
        }
    }
    
    cout << ways << endl;
    return 0;
}
