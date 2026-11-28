#define MAX(a, b) ((a) > (b) ? (a) : (b))

int trap(int* height, int heightSize) {
    if (heightSize == 0) return 0;
    int l = 0, r = heightSize - 1;
    int lMax = height[l], rMax = height[r];
    int water = 0;

    while (l < r) {
        if (lMax < rMax) {
            l++;
            lMax = MAX(lMax, height[l]);
            water += lMax - height[l];
        } else {
            r--;
            rMax = MAX(rMax, height[r]);
            water += rMax - height[r];
        }
    }
    return water;
}