int minimizedMaximum(int n, int* quantities, int quantitiesSize) {
    int left = 1, right = 0;
    for (int i = 0; i < quantitiesSize; i++) {
        if (quantities[i] > right) right = quantities[i];
    }
    int ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        long long needed = 0;
        for (int i = 0; i < quantitiesSize; i++) {
            needed += (quantities[i] + mid - 1) / mid;
        }
        if (needed <= n) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}