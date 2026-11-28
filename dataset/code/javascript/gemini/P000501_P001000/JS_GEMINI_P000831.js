function minDays(bloomDay, m, k) {
    if (m * k > bloomDay.length) return -1;
    let left = Math.min(...bloomDay);
    let right = Math.max(...bloomDay);
    let ans = -1;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let bouquets = 0, flowers = 0;
        for (const b of bloomDay) {
            if (b <= mid) {
                flowers++;
                if (flowers === k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        if (bouquets >= m) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { minDays };