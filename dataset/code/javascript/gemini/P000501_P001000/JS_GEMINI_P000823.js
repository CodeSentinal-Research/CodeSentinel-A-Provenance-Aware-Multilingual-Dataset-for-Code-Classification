function findKthPositive(arr, k) {
    let left = 0, right = arr.length - 1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        const missing = arr[mid] - (mid + 1);
        if (missing < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left + k;
}

module.exports = { findKthPositive };