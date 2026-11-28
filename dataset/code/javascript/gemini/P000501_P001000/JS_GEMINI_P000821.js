function singleNonDuplicate(nums) {
    let left = 0, right = nums.length - 1;
    // Binary search loop to narrow down range
    while (left < right) {
        // Calculate midpoint to prevent potential overflow
        let mid = Math.floor(left + (right - left) / 2);
        if (mid % 2 === 1) mid--;
        if (nums[mid] === nums[mid + 1]) {
            left = mid + 2;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

module.exports = { singleNonDuplicate };