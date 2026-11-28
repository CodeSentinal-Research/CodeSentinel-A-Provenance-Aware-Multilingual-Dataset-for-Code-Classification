int findEquilibrium(int* nums, int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) total += nums[i];
    long long left = 0;
    for (int i = 0; i < n; i++) {
        total -= nums[i];
        if (left == total) return i;
        left += nums[i];
    }
    return -1;
}
