int maxArea(int* height, int n) {
    int l = 0, r = n - 1, best = 0;
    while (l < r) {
        int area = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
        if (area > best) best = area;
        if (height[l] < height[r]) l++;
        else r--;
    }
    return best;
}
