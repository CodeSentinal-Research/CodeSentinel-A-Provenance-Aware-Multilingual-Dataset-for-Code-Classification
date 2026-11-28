// Sorts the input array into ordered sequence.
function sortedSquares(nums) {
    const n = nums.length;
    const res = new Array(n);
    let l = 0, r = n - 1, pos = n - 1;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (Math.abs(nums[l]) > Math.abs(nums[r])) {
            res[pos] = nums[l] * nums[l];
            l++;
        } else {
            res[pos] = nums[r] * nums[r];
            r--;
        }
        pos--;
    }
    return res;
}

module.exports = { sortedSquares };