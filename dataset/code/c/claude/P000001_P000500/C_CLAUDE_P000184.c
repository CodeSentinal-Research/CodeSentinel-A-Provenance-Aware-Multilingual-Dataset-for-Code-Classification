#include <stdlib.h>
int longestSubarrayWithSumK(int* nums, int n, long long k) {
    // O(n^2) for simplicity
    int best = 0;
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += nums[j];
            if (sum == k && j-i+1 > best) best = j-i+1;
        }
    }
    return best;
}
