#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int largestHistC(int* heights, int n) {
    int* stack = (int*)malloc((n + 1) * sizeof(int));
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n ? 0 : heights[i]);
        while (top >= 0 && heights[stack[top]] > h) {
            int idx = stack[top--];
            int w = (top < 0) ? i : i - stack[top] - 1;
            maxArea = MAX(maxArea, heights[idx] * w);
        }
        stack[++top] = i;
    }
    free(stack);
    return maxArea;
}

int maxArea(int** M, int n, int m) {
    int* heights = (int*)calloc(m, sizeof(int));
    int maxRect = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            heights[j] = (M[i][j] == 1 ? heights[j] + 1 : 0);
        }
        maxRect = MAX(maxRect, largestHistC(heights, m));
    }
    free(heights);
    return maxRect;
}