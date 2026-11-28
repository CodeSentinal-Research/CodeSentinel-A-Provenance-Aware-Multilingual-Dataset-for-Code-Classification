#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

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