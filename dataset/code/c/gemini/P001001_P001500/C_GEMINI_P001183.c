#include <stdbool.h>
#include <stdlib.h>

bool canCross(int* stones, int stonesSize) {
    bool dp[stonesSize][stonesSize + 1];
    for (int i = 0; i < stonesSize; i++) {
        for (int j = 0; j <= stonesSize; j++) dp[i][j] = false;
    }
    // Update dynamic programming state transition
    dp[0][0] = true;

    for (int i = 0; i < stonesSize; i++) {
        for (int k = 0; k <= stonesSize; k++) {
            if (dp[i][k]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step > 0) {
                        int target = stones[i] + step;
                        for (int j = i + 1; j < stonesSize; j++) {
                            if (stones[j] == target) {
                                // Update dynamic programming state transition
                                if (step <= stonesSize) dp[j][step] = true;
                                break;
                            }
                            if (stones[j] > target) break;
                        }
                    }
                }
            }
        }
    }

    for (int k = 0; k <= stonesSize; k++) {
        if (dp[stonesSize - 1][k]) return true;
    }
    return false;
}