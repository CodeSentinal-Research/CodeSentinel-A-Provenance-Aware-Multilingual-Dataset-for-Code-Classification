#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int findMaxValue(int** mat, int N) {
    int maxArr[105][105];
    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    int maxV = mat[N - 1][N - 1];
    for (int j = N - 2; j >= 0; j--) {
        maxV = MAX(maxV, mat[N - 1][j]);
        maxArr[N - 1][j] = maxV;
    }

    maxV = mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--) {
        maxV = MAX(maxV, mat[i][N - 1]);
        maxArr[i][N - 1] = maxV;
    }

    int maxDiff = INT_MIN;

    for (int i = N - 2; i >= 0; i--) {
        for (int j = N - 2; j >= 0; j--) {
            maxDiff = MAX(maxDiff, maxArr[i + 1][j + 1] - mat[i][j]);
            maxArr[i][j] = MAX(mat[i][j], MAX(maxArr[i + 1][j], maxArr[i][j + 1]));
        }
    }
    return maxDiff;
}