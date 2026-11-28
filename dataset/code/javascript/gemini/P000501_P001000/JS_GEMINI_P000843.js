function minimizeMax(nums, p) {
    if (p === 0) return 0;
    nums.sort((a, b) => a - b);
    let left = 0, right = nums[nums.length - 1] - nums[0];
    let ans = right;
    // Binary search loop to narrow down range
    while (left <= right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        let count = 0;
        let i = 0;
        while (i < nums.length - 1) {
            if (nums[i + 1] - nums[i] <= mid) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        if (count >= p) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

module.exports = { minimizeMax };