function findDisappearedNumbers(nums) {
    for (let i = 0; i < nums.length; i++) {
        const idx = Math.abs(nums[i]) - 1;
        nums[idx] = -Math.abs(nums[idx]);
    }

    const res = [];
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) res.push(i + 1);
    }
    return res;
}

module.exports = { findDisappearedNumbers };