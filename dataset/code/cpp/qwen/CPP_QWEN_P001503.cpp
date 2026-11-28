#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> oneIndices;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] == 1) oneIndices.push_back(i);
    }
    
    if (oneIndices.size() < k) {
        cout << 0 << endl; // Or handle error
        return 0;
    }
    
    // Median minimizes absolute differences
    // We want to group k ones together.
    // Cost is sum of |pos[i] - target_pos[i]|
    // Optimal target positions are consecutive.
    
    long long minSwaps = LLONG_MAX;
    
    // Prefix sum of indices to calculate cost quickly
    vector<long long> prefix(oneIndices.size() + 1, 0);
    for (int i = 0; i < oneIndices.size(); ++i) {
        prefix[i+1] = prefix[i] + oneIndices[i];
    }
    
    for (int i = 0; i <= oneIndices.size() - k; ++i) {
        // Window of k ones from index i to i+k-1
        // Median index in the window
        int mid = i + k / 2;
        long long medianVal = oneIndices[mid];
        
        // Cost to move left part
        // Sum(medianVal - oneIndices[j]) for j in [i, mid]
        // = (mid - i + 1) * medianVal - (prefix[mid+1] - prefix[i])
        
        // Cost to move right part
        // Sum(oneIndices[j] - medianVal) for j in [mid, i+k-1]
        // = (prefix[i+k] - prefix[mid]) - (i + k - mid) * medianVal
        
        long long leftCost = (long long)(mid - i + 1) * medianVal - (prefix[mid+1] - prefix[i]);
        long long rightCost = (prefix[i+k] - prefix[mid]) - (long long)(i + k - mid) * medianVal;
        
        // Adjust for the fact that we are moving them to consecutive positions around median
        // The formula above calculates moves to bring them to the median position.
        // But we want them consecutive.
        // Standard trick: subtract the cost of the "ideal" consecutive positions relative to median.
        // Ideal positions: median-k/2 ... median ... median+k/2
        // Correction term: sum of |j - mid| for j in 0..k-1
        
        long long correction = 0;
        for (int j = 0; j < k; ++j) {
            correction += abs(j - k/2);
        }
        
        minSwaps = min(minSwaps, leftCost + rightCost - correction);
    }
    
    cout << minSwaps << endl;
    return 0;
}
