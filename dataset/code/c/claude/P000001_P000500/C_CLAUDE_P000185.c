#include <stdlib.h>
int longestSubarrayEqual01(int* nums, int n) {
    // O(n^2)
    int best = 0;
    for (int i = 0; i < n; i++) {
        int zeros = 0, ones = 0;
        for (int j = i; j < n; j++) {
            if (nums[j]==0) zeros++; else ones++;
            if (zeros==ones && j-i+1>best) best=j-i+1;
        }
    }
    return best;
}
