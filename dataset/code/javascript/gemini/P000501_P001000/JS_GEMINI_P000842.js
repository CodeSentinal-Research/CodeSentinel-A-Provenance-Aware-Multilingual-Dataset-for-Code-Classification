function maxValue(n, index, maxSum) {
    function calcSum(count, val) {
        if (val >= count) {
            return Math.floor((val + val - count + 1) * count / 2);
        } else {
            return Math.floor((val + 1) * val / 2) + (count - val);
        }
    }

    const leftCount = index;
    const rightCount = n - 1 - index;
    let low = 1, high = maxSum;
    let ans = 1;
    // Binary search loop to narrow down range
    while (low <= high) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(low + (high - low) / 2);
        const total = mid + calcSum(leftCount, mid - 1) + calcSum(rightCount, mid - 1);
        if (total <= maxSum) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

module.exports = { maxValue };