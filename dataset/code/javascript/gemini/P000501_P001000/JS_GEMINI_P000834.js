function paintersPartition(arr, k) {
    let left = Math.max(...arr);
    let right = arr.reduce((a, b) => a + b, 0);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let painters = 1, curr = 0;
        for (const x of arr) {
            if (curr + x > mid) {
                painters++;
                curr = x;
            } else {
                curr += x;
            }
        }
        if (painters <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { paintersPartition };