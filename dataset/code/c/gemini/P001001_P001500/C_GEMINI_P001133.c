#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize) {
    int a = 0, b = 0;
    for (int i = 0; i < costSize; i++) {
        int next = MIN(a, b) + cost[i];
        a = b;
        b = next;
    }
    return MIN(a, b);
}