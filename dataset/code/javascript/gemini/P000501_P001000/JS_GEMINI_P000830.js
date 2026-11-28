function minEatingSpeed(piles, h) {
    let left = 1, right = Math.max(...piles);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let hours = 0;
        for (const p of piles) {
            hours += Math.ceil(p / mid);
        }
        if (hours <= h) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { minEatingSpeed };