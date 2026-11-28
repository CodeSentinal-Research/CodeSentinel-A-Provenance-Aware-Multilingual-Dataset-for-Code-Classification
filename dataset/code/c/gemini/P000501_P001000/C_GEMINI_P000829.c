int shipWithinDays(int* weights, int weightsSize, int days) {
    int left = 0, right = 0;
    for (int i = 0; i < weightsSize; i++) {
        if (weights[i] > left) left = weights[i];
        right += weights[i];
    }
    int ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        int mid = left + (right - left) / 2;
        int d = 1, curr = 0;
        for (int i = 0; i < weightsSize; i++) {
            if (curr + weights[i] > mid) {
                d++;
                curr = weights[i];
            } else {
                curr += weights[i];
            }
        }
        if (d <= days) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}