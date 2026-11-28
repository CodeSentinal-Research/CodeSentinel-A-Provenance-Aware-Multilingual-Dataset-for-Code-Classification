// Sorts the input array into ordered sequence.
function findUnsortedSubarray(nums) {
    const sorted = [...nums].sort((a, b) => a - b);
    let l = 0, r = nums.length - 1;

    while (l < nums.length && nums[l] === sorted[l]) l++;
    while (r > l && nums[r] === sorted[r]) r--;

    return r > l ? r - l + 1 : 0;
}

module.exports = { findUnsortedSubarray };