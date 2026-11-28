int maximumCandies(int* candies, int candiesSize, long long k) {
    int left = 1, right = 0;
    for (int i = 0; i < candiesSize; i++) {
        if (candies[i] > right) right = candies[i];
    }
    int ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        long long children = 0;
        for (int i = 0; i < candiesSize; i++) {
            children += candies[i] / mid;
        }
        if (children >= k) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}