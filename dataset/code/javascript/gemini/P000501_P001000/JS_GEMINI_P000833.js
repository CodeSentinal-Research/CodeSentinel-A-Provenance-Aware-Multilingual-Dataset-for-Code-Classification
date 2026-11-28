function findPages(arr, k) {
    if (k > arr.length) return -1;
    let left = Math.max(...arr);
    let right = arr.reduce((a, b) => a + b, 0);
    let ans = -1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let students = 1, pages = 0;
        for (const x of arr) {
            if (pages + x > mid) {
                students++;
                pages = x;
            } else {
                pages += x;
            }
        }
        if (students <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { findPages };