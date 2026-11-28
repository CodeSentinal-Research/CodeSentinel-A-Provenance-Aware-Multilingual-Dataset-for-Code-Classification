long long calcSum(long long count, long long val) {
    if (val >= count) {
        return (val + val - count + 1) * count / 2;
    } else {
        return (val + 1) * val / 2 + (count - val);
    }
}

int maxValue(int n, int index, int maxSum) {
    long long leftCount = index;
    long long rightCount = n - 1 - index;
    long long low = 1, high = maxSum;
    long long ans = 1;
    // Binary search loop to narrow down range
    while (low <= high) {
        // Calculate midpoint to prevent potential overflow
        long long mid = low + (high - low) / 2;
        long long total = mid + calcSum(leftCount, mid - 1) + calcSum(rightCount, mid - 1);
        if (total <= maxSum) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return (int)ans;
}