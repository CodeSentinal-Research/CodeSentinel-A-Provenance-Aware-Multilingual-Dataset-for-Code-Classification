#include <iostream>
using namespace std;

long long calcSum(long long peak, long long len) {
    // Sum of 1, 2, ..., peak-1, peak, peak-1, ...
    // Actually, we calculate sum of array of length 'len' with max value 'peak'
    // The shape is a pyramid.
    // Left side: min(peak, len_left) terms.
    // Right side: min(peak, len_right) terms.
    
    // This function is tricky. Let's use the property:
    // Minimum sum for index 'index' with value 'peak' in array of size 'n'
    // is calculated by summing the arithmetic progression downwards from peak.
    
    // Sum of 1 to x is x*(x+1)/2
    auto sumSeq = [](long long x) -> long long {
        return x * (x + 1) / 2;
    };
    
    // We don't have n/index here, this helper is for generic check.
    // Let's move logic to main/check function.
    return 0;
}

bool isValid(long long n, long long index, long long maxSum, long long peak) {
    // Calculate minimum sum required if nums[index] = peak
    // Left part: index elements. Values: peak-1, peak-2, ...
    // Right part: n-index-1 elements. Values: peak-1, peak-2, ...
    
    auto calcSideSum = [](long long peak, long long count) -> long long {
        // We want sum of 'count' numbers decreasing from peak-1.
        // Sequence: peak-1, peak-2, ...
        // If count < peak, we sum peak-1 down to peak-count.
        // Sum = sum(1..peak-1) - sum(1..peak-1-count)
        // If count >= peak, we sum peak-1 down to 1, then rest are 1s.
        
        long long actualTerms = min(count, peak - 1);
        long long sumDecreasing = (peak - 1) * peak / 2 - (peak - 1 - actualTerms) * (peak - actualTerms) / 2;
        long long remainingOnes = count - actualTerms;
        return sumDecreasing + remainingOnes;
    };
    
    long long leftSum = calcSideSum(peak, index);
    long long rightSum = calcSideSum(peak, n - index - 1);
    
    return (leftSum + peak + rightSum) <= maxSum;
}

int main() {
    long long n, index, maxSum;
    cin >> n >> index >> maxSum;
    
    long long low = 1, high = maxSum;
    long long ans = 1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (isValid(n, index, maxSum, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
