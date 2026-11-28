#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maximumSumRectangle(int R, int C, int** M) {
    int maxSum = INT_MIN;

    for (int l = 0; l < C; l++) {
        int temp[505] = {0};
        for (int r = l; r < C; r++) {
            for (int i = 0; i < R; i++) {
                temp[i] += M[i][r];
            }

            int cur = temp[0], maxSoFar = temp[0];
            for (int i = 1; i < R; i++) {
                cur = MAX(temp[i], cur + temp[i]);
                maxSoFar = MAX(maxSoFar, cur);
            }

            maxSum = MAX(maxSum, maxSoFar);
        }
    }
    return maxSum;
}