#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCost(int** costs, int costsSize, int* costsColSize) {
    if (costsSize == 0) return 0;
    int r = 0, g = 0, b = 0;
    for (int i = 0; i < costsSize; i++) {
        int nr = costs[i][0] + MIN(g, b);
        int ng = costs[i][1] + MIN(r, b);
        int nb = costs[i][2] + MIN(r, g);
        r = nr;
        g = ng;
        b = nb;
    }
    return MIN(r, MIN(g, b));
}