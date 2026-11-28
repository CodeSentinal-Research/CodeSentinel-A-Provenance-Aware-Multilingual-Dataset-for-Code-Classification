double arrayAverage(int* nums, int n) {
    long long s = 0;
    for (int i = 0; i < n; i++) s += nums[i];
    return (double)s / n;
}
