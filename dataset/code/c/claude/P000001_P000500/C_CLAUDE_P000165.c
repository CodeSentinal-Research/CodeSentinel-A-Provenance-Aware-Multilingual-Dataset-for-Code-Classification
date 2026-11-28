int maxProduct(int* nums, int n) {
    int best = nums[0], curMax = nums[0], curMin = nums[0];
    for (int i = 1; i < n; i++) {
        int x = nums[i];
        int a = curMax*x, b = curMin*x;
        int newMax = x > a ? (x > b ? x : b) : (a > b ? a : b);
        curMin = x < a ? (x < b ? x : b) : (a < b ? a : b);
        curMax = newMax;
        if (curMax > best) best = curMax;
    }
    return best;
}
