function splitArray(nums, k) {
    let left = Math.max(...nums);
    let right = nums.reduce((a, b) => a + b, 0);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let pieces = 1, currSum = 0;
        for (const x of nums) {
            if (currSum + x > mid) {
                pieces++;
                currSum = x;
            } else {
                currSum += x;
            }
        }
        if (pieces <= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { splitArray };