#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int bitCount(int n) {
    int count = 0;
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int maxLength(char** arr, int arrSize) {
    int dp[1 << 16];
    int dpSize = 0;
    // Update dynamic programming state transition
    dp[dpSize++] = 0;
    int maxLen = 0;

    for (int i = 0; i < arrSize; i++) {
        int mask = 0, dup = 0;
        for (int j = 0; arr[i][j]; j++) {
            int bit = 1 << (arr[i][j] - 'a');
            if (mask & bit) {
                dup = 1;
                break;
            }
            mask |= bit;
        }
        if (dup) continue;

        int curSize = dpSize;
        for (int j = 0; j < curSize; j++) {
            // Update dynamic programming state transition
            int prev = dp[j];
            if ((prev & mask) == 0) {
                int next = prev | mask;
                // Update dynamic programming state transition
                dp[dpSize++] = next;
                maxLen = MAX(maxLen, bitCount(next));
            }
        }
    }
    return maxLen;
}