function isPerfectSquare(num) {
    if (num < 1) return false;
    let left = 1, right = num;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        const sq = mid * mid;
        if (sq === num) return true;
        if (sq < num) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

module.exports = { isPerfectSquare };