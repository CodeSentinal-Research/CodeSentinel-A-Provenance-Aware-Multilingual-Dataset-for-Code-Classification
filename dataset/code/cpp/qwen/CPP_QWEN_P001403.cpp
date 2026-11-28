#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isArithmetic(vector<int>& sub) {
    if (sub.size() <= 2) return true;
    sort(sub.begin(), sub.end());
    int diff = sub[1] - sub[0];
    for (int i = 2; i < sub.size(); ++i) {
        if (sub[i] - sub[i-1] != diff) return false;
    }
    return true;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        // Assuming 1-based input for queries based on typical competitive programming, 
        // but problem statement says L and R. Let's assume 0-based or adjust.
        // Standard is often 0-based in C++ vectors if not specified.
        // Given constraints, let's just extract subarray.
        
        vector<int> sub(nums.begin() + l, nums.begin() + r + 1);
        cout << (isArithmetic(sub) ? "YES" : "NO") << endl;
    }
    return 0;
}
