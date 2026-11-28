// maximum-swap | LC 670 | Medium | https://leetcode.com/problems/maximum-swap/
// Approaches: 1) try all O(d^2) swaps and keep the max (d <= 9, so this is fine)
//             2) last-occurrence table, one greedy pass  <- primary
// Greedy rule: scanning left to right, the first position that can be improved must be improved,
// and it must be swapped with the LAST occurrence of the largest digit to its right. "Largest"
// because a bigger digit in a higher place always wins; "last" because moving the rightmost copy
// leaves the bigger remaining digits further left.
#include <bits/stdc++.h>
using namespace std;

// ===== Approach 2: last occurrence of each digit. Time O(d), Space O(1). PRIMARY.
// last[v] = rightmost index where digit v appears. At position i, look for the biggest v > s[i]
// that occurs later; the first i where one exists is the swap, and there is exactly one swap.
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int last[10];
        for (int v = 0; v < 10; ++v) last[v] = -1;
        for (int i = 0; i < (int)s.size(); ++i) last[s[i] - '0'] = i;
        for (int i = 0; i < (int)s.size(); ++i)
            for (int v = 9; v > s[i] - '0'; --v)
                if (last[v] > i) {
                    swap(s[i], s[last[v]]);
                    return stoi(s);
                }
        return num;                                  // already non-increasing, no swap helps
    }
};

// ===== Approach 1: brute force over all swaps. Time O(d^2), Space O(d).
// num <= 10^8 means at most 9 digits, so 36 swaps. Perfectly acceptable, and it is the reference
// the greedy version is checked against below.
class SolutionBrute {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int best = num;
        for (size_t i = 0; i < s.size(); ++i)
            for (size_t j = i + 1; j < s.size(); ++j) {
                swap(s[i], s[j]);
                best = max(best, stoi(s));           // no leading-zero problem: s[0] only grows
                swap(s[i], s[j]);
            }
        return best;
    }
};

#ifndef LEETCODE_SUBMIT
static void check(int num, int want) {
    assert(Solution().maximumSwap(num) == want);
    assert(SolutionBrute().maximumSwap(num) == want);
}
int main() {
    check(2736, 7236);                               // sample 1
    check(9973, 9973);                               // sample 2, already maximal
    check(0, 0);                                     // lower bound
    check(7, 7);                                     // single digit
    check(10, 10);                                   // swapping would create a leading zero
    check(1993, 9913);                               // pick the LAST 9, not the first
    check(98368, 98863);                             // improvement is not at index 0
    check(100000000, 100000000);                     // upper bound, nothing to gain
    check(11111112, 21111111);                       // the useful digit is at the very end
    check(1111, 1111);                               // all digits equal
    for (int n = 0; n <= 20000; ++n)                 // exhaustive agreement with the brute force
        assert(Solution().maximumSwap(n) == SolutionBrute().maximumSwap(n));
    {                                                // random 9-digit values at the stated limit
        mt19937 rng(7);
        for (int t = 0; t < 20000; ++t) {
            int n = rng() % 100000001;
            assert(Solution().maximumSwap(n) == SolutionBrute().maximumSwap(n));
        }
    }
    puts("maximum-swap: ok");
}
#endif
