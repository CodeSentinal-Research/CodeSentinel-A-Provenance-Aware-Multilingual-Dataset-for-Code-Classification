// Day 2 — Subarray Sums Divisible by K (LC #974)  [Core 2, 🟡]
// Pattern: prefix sum + hash map on remainders
//
// Key insight: subarray (l..r] is divisible by K when pre[r] % K == pre[l] % K.
// So count, for each remainder, how many prefixes have produced it.
// Pairs of equal remainders = valid subarrays.
//
// Gotcha: C++ % can be negative for negative numbers.
// Normalize: ((x % k) + k) % k

#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> remCount;
    remCount[0] = 1;   // empty prefix has remainder 0
    int prefSum = 0, ans = 0;

    for (int x : nums) {
        prefSum += x;
        int rem = ((prefSum % k) + k) % k;   // normalize to [0, k-1]

        // TODO: add remCount[rem] to ans (each previous prefix with same remainder
        //       pairs with current prefix to form a valid subarray)

        // TODO: increment remCount[rem]
    }
    return ans;
}

// ---- test harness ----
int main() {
    vector<int> a = {4, 5, 0, -2, -3, 1};  int k1 = 5;  // expect 7
    cout << subarraysDivByK(a, k1) << "\n";

    vector<int> b = {5};  int k2 = 9;  // expect 0
    cout << subarraysDivByK(b, k2) << "\n";
    return 0;
}
