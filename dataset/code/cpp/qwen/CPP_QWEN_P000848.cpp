#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    long long prefixSum = 0;
    long long maxVal = 0;
    
    for (int i = 0; i < n; ++i) {
        prefixSum += nums[i];
        // The average of the first i+1 elements is the lower bound for the max element in that prefix
        // because we can only move left.
        long long avg = (prefixSum + i) / (i + 1); // Ceiling division
        maxVal = max(maxVal, avg);
    }
    
    cout << maxVal << endl;
    return 0;
}
