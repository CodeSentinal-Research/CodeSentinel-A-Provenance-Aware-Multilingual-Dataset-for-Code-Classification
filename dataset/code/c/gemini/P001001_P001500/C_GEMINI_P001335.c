#include <stdbool.h>
#include <stdlib.h>

int cmpDescMatch(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

bool backtrackMatch(int* matchsticks, int n, int idx, int side, int sides[4]) {
    if (idx == n) return true;
    for (int i = 0; i < 4; i++) {
        if (sides[i] + matchsticks[idx] <= side) {
            sides[i] += matchsticks[idx];
            if (backtrackMatch(matchsticks, n, idx + 1, side, sides)) return true;
            sides[i] -= matchsticks[idx];
        }
        if (sides[i] == 0) break;
    }
    return false;
}

bool makesquare(int* matchsticks, int matchsticksSize) {
    int total = 0;
    for (int i = 0; i < matchsticksSize; i++) total += matchsticks[i];
    if (total % 4 != 0) return false;
    int side = total / 4;

    qsort(matchsticks, matchsticksSize, sizeof(int), cmpDescMatch);
    if (matchsticks[0] > side) return false;

    int sides[4] = {0};
    return backtrackMatch(matchsticks, matchsticksSize, 0, side, sides);
}