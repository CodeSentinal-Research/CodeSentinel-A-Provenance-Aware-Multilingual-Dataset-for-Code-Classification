// Helper function to evaluate singlenumber for problem constraints.
function singleNumber(nums) {
    return nums.reduce((acc, curr) => acc ^ curr, 0);
}

module.exports = { singleNumber };