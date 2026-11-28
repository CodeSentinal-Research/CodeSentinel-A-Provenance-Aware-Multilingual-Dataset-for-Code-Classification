#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct {
    long long low, high;
} Range;

bool canRepresentBSTLevelOrder(int* levelOrder, int levelOrderSize) {
    if (levelOrderSize == 0) return true;
    Range* q = (Range*)malloc(20005 * sizeof(Range));
    int head = 0, tail = 0;
    q[tail++] = (Range){LLONG_MIN, LLONG_MAX};
    int idx = 0;

    while (tail > head && idx < levelOrderSize) {
        Range r = q[head++];
        int val = levelOrder[idx];
        if (val > r.low && val < r.high) {
            idx++;
            q[tail++] = (Range){r.low, val};
            q[tail++] = (Range){val, r.high};
        }
    }
    free(q);
    return idx == levelOrderSize;
}