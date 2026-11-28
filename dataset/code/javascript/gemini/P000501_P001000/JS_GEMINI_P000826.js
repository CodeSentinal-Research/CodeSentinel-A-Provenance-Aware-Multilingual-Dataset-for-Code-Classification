function arrangeCoins(n) {
    let left = 1, right = n;
    let ans = 0;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        const curr = (mid * (mid + 1)) / 2;
        if (curr <= n) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

module.exports = { arrangeCoins };