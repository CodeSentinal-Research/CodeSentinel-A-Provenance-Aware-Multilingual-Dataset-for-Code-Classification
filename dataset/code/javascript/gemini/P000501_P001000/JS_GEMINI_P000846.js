function minimizedMaximum(n, quantities) {
    let left = 1, right = Math.max(...quantities);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let needed = 0;
        for (const q of quantities) {
            needed += Math.ceil(q / mid);
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

module.exports = { minimizedMaximum };