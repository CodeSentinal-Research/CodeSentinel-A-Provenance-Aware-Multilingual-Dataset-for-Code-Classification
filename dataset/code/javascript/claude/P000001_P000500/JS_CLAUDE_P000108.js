function isSortedDesc(nums) {
    for (let i = 0; i < nums.length - 1; i++)
        if (nums[i] < nums[i+1]) return false;
    return true;
}
module.exports = { isSortedDesc };
