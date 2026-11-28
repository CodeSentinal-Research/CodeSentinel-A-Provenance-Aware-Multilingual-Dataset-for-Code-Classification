#include <stdlib.h>
#include <stdbool.h>

bool backtrackDist(int idx, int n, int* res, int len, bool* used) {
    while (idx < len && res[idx] != 0) idx++;
    if (idx == len) return true;

    for (int num = n; num >= 1; num--) {
        if (used[num]) continue;
        if (num == 1) {
            res[idx] = 1;
            used[1] = true;
            if (backtrackDist(idx + 1, n, res, len, used)) return true;
            res[idx] = 0;
            used[1] = false;
        } else if (idx + num < len && res[idx + num] == 0) {
            res[idx] = num;
            res[idx + num] = num;
            used[num] = true;
            if (backtrackDist(idx + 1, n, res, len, used)) return true;
            res[idx] = 0;
            res[idx + num] = 0;
            used[num] = false;
        }
    }
    return false;
}

int* constructDistancedSequence(int n, int* returnSize) {
    int len = 2 * n - 1;
    *returnSize = len;
    int* res = (int*)calloc(len, sizeof(int));
    bool used[25] = {false};
    backtrackDist(0, n, res, len, used);
    return res;
}