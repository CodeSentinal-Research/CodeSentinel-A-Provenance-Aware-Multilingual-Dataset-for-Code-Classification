#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int low = 1, high = 2000000000; // Large enough upper bound
    while (low < high) {
        int mid = low + (high - low) / 2;
        // Count how many numbers are missing up to 'mid'
        // Missing count = mid - (number of elements in arr <= mid)
        
        int idx = upper_bound(arr.begin(), arr.end(), mid) - arr.begin();
        int missing = mid - idx;
        
        if (missing < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    // Adjust if low lands on an existing number
    // Actually, the binary search finds the k-th missing number directly if we interpret correctly.
    // Let's refine: The k-th missing number is such that there are exactly k-1 missing numbers before it.
    
    // Alternative simpler approach for small constraints or specific logic:
    // Just iterate? No, O(N) is fine for N=10^5 but BS is requested.
    
    // Correct BS logic:
    // We want smallest X such that count_missing(X) >= k
    // count_missing(X) = X - count_elements_le_X
    
    cout << low << endl;
    return 0;
}
