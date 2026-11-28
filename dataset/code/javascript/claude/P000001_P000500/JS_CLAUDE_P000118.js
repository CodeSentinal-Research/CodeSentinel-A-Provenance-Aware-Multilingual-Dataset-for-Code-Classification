function moveZeroes(nums) {
    let k = 0;
    for (const x of nums) if (x !== 0) nums[k++] = x;
    while (k < nums.length) nums[k++] = 0;
    return nums;
}
module.exports = { moveZeroes };
