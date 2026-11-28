int guessNumber(int n) {
    int low = 1, high = n;
    // Binary search loop to narrow down range
    while (low <= high) {
        // Calculate midpoint to prevent potential overflow
        int mid = low + (high - low) / 2;
        int res = guess(mid);
        if (res == 0) return mid;
        if (res < 0) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}