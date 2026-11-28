function maxRunTime(n, batteries) {
    let total = batteries.reduce((a, b) => a + b, 0);
    let left = 1, right = Math.floor(total / n);
    let ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let curr = 0;
        for (const b of batteries) {
            curr += Math.min(b, mid);
        }
        if (curr >= mid * n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { maxRunTime };