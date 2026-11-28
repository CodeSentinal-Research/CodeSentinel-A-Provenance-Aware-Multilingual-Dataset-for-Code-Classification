function findPeakElement(nums) {
    let l = 0, r = nums.length - 1;
    while (l < r) {
        const mid = Math.floor((l + r) / 2);
        if (nums[mid] > nums[mid + 1]) r = mid;
        else l = mid + 1;
    }
    return l;
}
module.exports = { findPeakElement };
