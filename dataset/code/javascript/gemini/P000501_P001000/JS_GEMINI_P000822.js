function findClosestElements(arr, k, x) {
    let left = 0, right = arr.length - k;
    // Binary search loop to narrow down range
    while (left < right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        if (x - arr[mid] > arr[mid + k] - x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return arr.slice(left, left + k);
}

module.exports = { findClosestElements };