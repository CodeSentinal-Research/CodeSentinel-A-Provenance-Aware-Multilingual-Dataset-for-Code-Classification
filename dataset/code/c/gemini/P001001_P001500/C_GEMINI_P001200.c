#include <string.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int n = matrixColSize[0];
    int heights[n + 1];
    memset(heights, 0, sizeof(heights));
    int maxArea = 0;

    for (int r = 0; r < matrixSize; r++) {
        for (int i = 0; i < n; i++) {
            heights[i] = (matrix[r][i] == '1') ? heights[i] + 1 : 0;
        }
        int stack[n + 2];
        int top = 0;
        stack[top++] = -1;

        for (int i = 0; i <= n; i++) {
            while (top > 1 && heights[stack[top - 1]] >= heights[i]) {
                int h = heights[stack[--top]];
                int w = i - stack[top - 1] - 1;
                if (h * w > maxArea) maxArea = h * w;
            }
            stack[top++] = i;
        }
    }
    return maxArea;
}