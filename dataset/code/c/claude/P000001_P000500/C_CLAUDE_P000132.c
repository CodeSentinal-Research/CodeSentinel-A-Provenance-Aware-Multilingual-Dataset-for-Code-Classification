int equilibriumIndex(int* nums, int n) {
    long long total = 0;
    for (int i = 0; i < n; i++) total += nums[i];
    long long leftSum = 0;
    for (int i = 0; i < n; i++) {
        total -= nums[i];
        if (leftSum == total) return i;
        leftSum += nums[i];
    }
    return -1;
}
