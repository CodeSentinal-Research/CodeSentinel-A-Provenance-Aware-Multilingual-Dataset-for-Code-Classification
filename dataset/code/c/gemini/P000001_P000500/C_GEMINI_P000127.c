#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int l = 0, r = heightSize - 1;
    int maxWater = 0;
    while (l < r) {
        int h = MIN(height[l], height[r]);
        maxWater = MAX(maxWater, h * (r - l));
        if (height[l] < height[r]) l++;
        else r--;
    }
    return maxWater;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int *height = (int *)malloc(n * sizeof(int));
    if (!height) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);
    }

    printf("%d\n", maxArea(height, n));

    free(height);
    return 0;
}
