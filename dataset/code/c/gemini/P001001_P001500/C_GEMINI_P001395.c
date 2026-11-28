#include <stdlib.h>

int cmpIntBoom(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize) {
    int ans = 0;
    int* dists = (int*)malloc(pointsSize * sizeof(int));

    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            int dx = points[i][0] - points[j][0];
            int dy = points[i][1] - points[j][1];
            dists[j] = dx * dx + dy * dy;
        }
        qsort(dists, pointsSize, sizeof(int), cmpIntBoom);

        int count = 1;
        for (int j = 1; j < pointsSize; j++) {
            if (dists[j] == dists[j - 1]) {
                count++;
            } else {
                ans += count * (count - 1);
                count = 1;
            }
        }
        ans += count * (count - 1);
    }

    free(dists);
    return ans;
}