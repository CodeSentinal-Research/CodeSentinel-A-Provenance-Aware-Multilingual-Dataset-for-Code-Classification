function findMin(nums) {
    let left = 0, right = nums.length - 1;
    // Binary search loop to narrow down range
    while (left < right) {
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor(left + (right - left) / 2);
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

module.exports = { findMin };