#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minTaps(int n, int* ranges, int rangesSize) {
    int maxReach[n + 1];
    memset(maxReach, 0, sizeof(maxReach));

    for (int i = 0; i <= n; i++) {
        int left = MAX(0, i - ranges[i]);
        int right = MIN(n, i + ranges[i]);
        maxReach[left] = MAX(maxReach[left], right);
    }

    int taps = 0, curEnd = 0, nextEnd = 0;
    for (int i = 0; i < n; i++) {
        nextEnd = MAX(nextEnd, maxReach[i]);
        if (i == curEnd) {
            if (nextEnd <= i) return -1;
            taps++;
            curEnd = nextEnd;
        }
    }
    return taps;
}