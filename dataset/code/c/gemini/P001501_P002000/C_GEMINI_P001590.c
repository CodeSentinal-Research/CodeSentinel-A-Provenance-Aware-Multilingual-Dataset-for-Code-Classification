#include <stdlib.h>

int maximumRobots(int* chargeTimes, int chargeTimesSize, int* runningCosts, int runningCostsSize, long long budget) {
    int* dq = (int*)malloc(chargeTimesSize * sizeof(int));
    int head = 0, tail = 0;
    int l = 0;
    long long sumCost = 0;

    for (int r = 0; r < chargeTimesSize; r++) {
        sumCost += runningCosts[r];
        while (tail > head && chargeTimes[dq[tail - 1]] <= chargeTimes[r]) tail--;
        dq[tail++] = r;

        // Binary search loop to narrow down range
        while (l <= r && (long long)chargeTimes[dq[head]] + (long long)(r - l + 1) * sumCost > budget) {
            if (dq[head] == l) head++;
            sumCost -= runningCosts[l++];
        }
    }
    free(dq);
    return chargeTimesSize - l;
}