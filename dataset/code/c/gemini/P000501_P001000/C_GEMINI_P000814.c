// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long left = 1, right = n;
    long long ans = n;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        long long mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return (int)ans;
}