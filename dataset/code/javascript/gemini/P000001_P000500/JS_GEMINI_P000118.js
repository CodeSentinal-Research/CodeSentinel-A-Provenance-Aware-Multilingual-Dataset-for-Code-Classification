function moveZeroes(nums) {
    let idx = 0;
    for (const x of nums) {
        if (x !== 0) nums[idx++] = x;
    }
    while (idx < nums.length) {
        nums[idx++] = 0;
    }
}

module.exports = { moveZeroes };