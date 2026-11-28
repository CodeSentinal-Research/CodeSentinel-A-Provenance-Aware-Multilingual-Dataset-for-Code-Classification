function shipWithinDays(weights, days) {
    let left = Math.max(...weights);
    let right = weights.reduce((a, b) => a + b, 0);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let d = 1, curr = 0;
        for (const w of weights) {
            if (curr + w > mid) {
                d++;
                curr = w;
            } else {
                curr += w;
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

module.exports = { shipWithinDays };