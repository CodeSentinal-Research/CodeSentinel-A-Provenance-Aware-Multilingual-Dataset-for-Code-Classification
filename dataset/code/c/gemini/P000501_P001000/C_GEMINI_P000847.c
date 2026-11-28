long long maxRunTime(int n, int* batteries, int batteriesSize) {
    long long total = 0;
    for (int i = 0; i < batteriesSize; i++) total += batteries[i];
    long long left = 1, right = total / n;
    long long ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        long long curr = 0;
        for (int i = 0; i < batteriesSize; i++) {
            curr += (batteries[i] < mid ? batteries[i] : mid);
        }
        if (curr >= mid * n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}