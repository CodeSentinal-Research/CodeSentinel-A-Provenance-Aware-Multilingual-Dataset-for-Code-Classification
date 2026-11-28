// Helper function to evaluate finddisappearednumbers for problem constraints.
function findDisappearedNumbers(nums) {
    for (const x of nums) {
        const idx = Math.abs(x) - 1;
        if (nums[idx] > 0) nums[idx] = -nums[idx];
    }

    const res = [];
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] > 0) res.push(i + 1);
    }
    return res;
}

module.exports = { findDisappearedNumbers };