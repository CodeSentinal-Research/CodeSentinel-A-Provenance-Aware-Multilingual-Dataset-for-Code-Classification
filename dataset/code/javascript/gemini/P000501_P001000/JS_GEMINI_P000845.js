function minCapability(nums, k) {
    let left = Math.min(...nums);
    let right = Math.max(...nums);
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let count = 0;
        let i = 0;
        while (i < nums.length) {
            if (nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        if (count >= k) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { minCapability };