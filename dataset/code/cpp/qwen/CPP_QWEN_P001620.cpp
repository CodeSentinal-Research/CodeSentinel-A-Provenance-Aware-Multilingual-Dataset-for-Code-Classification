#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    // Prefix sums for even indices (0, 2, ...) and odd indices (1, 3, ...)
    // But problem says "alternate positions starting from left endpoint"
    // So for query [L, R], we sum nums[L], nums[L+2], ...
    
    // We can precompute two prefix sums: one for even-indexed elements in original array, one for odd.
    // But L varies.
    // Simpler: Just iterate for each query if Q is small? No, Q up to 10^5.
    // We need O(1) per query.
    // Let's create two arrays: prefixEven and prefixOdd based on original indices.
    // If L is even, we sum from prefixEven. If L is odd, from prefixOdd.
    
    vector<long long> prefixEven(n + 1, 0);
    vector<long long> prefixOdd(n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
        prefixEven[i+1] = prefixEven[i];
        prefixOdd[i+1] = prefixOdd[i];
        if (i % 2 == 0) prefixEven[i+1] += nums[i];
        else prefixOdd[i+1] += nums[i];
    }
    
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        long long sum = 0;
        // This approach is tricky because "alternate from L" depends on L.
        // If L is even, we take indices L, L+2... which are even indices in original array.
        // If L is odd, we take indices L, L+2... which are odd indices in original array.
        
        if (l % 2 == 0) {
            // Sum of even indices from l to r
            // Number of terms: ((r - l) / 2) + 1
            // Last index: l + 2*k <= r
            int lastIdx = l + 2 * ((r - l) / 2);
            // Sum = prefixEven[lastIdx+1] - prefixEven[l]
             sum = prefixEven[lastIdx+1] - prefixEven[l];
        } else {
            int lastIdx = l + 2 * ((r - l) / 2);
            sum = prefixOdd[lastIdx+1] - prefixOdd[l];
        }
        
        cout << sum << endl;
    }
    return 0;
}
