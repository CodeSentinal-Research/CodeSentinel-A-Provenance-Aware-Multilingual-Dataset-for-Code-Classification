function minimumSize(nums, maxOperations) {
    let left = 1, right = Math.max(...nums);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let ops = 0;
        for (const x of nums) {
            ops += Math.floor((x - 1) / mid);
        }
        if (ops <= maxOperations) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { minimumSize };