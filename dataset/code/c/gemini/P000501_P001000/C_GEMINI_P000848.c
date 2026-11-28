int minimizeArrayValue(int* nums, int numsSize) {
    long long ans = 0;
    long long total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
        long long val = (total + i) / (i + 1);
        if (val > ans) ans = val;
    }
    return (int)ans;
}