// Sorts the input array into ordered sequence.
function sortArrayByParity(nums) {
    let l = 0, r = nums.length - 1;
    while (l < r) {
        if (nums[l] % 2 > nums[r] % 2) {
            const temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
        }
        if (nums[l] % 2 === 0) l++;
        if (nums[r] % 2 === 1) r--;
    }
    return nums;
}

module.exports = { sortArrayByParity };