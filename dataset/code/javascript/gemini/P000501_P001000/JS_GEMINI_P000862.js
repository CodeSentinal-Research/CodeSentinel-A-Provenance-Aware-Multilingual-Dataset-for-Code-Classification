// Helper function to evaluate singlenumber for problem constraints.
function singleNumber(nums) {
    let ones = 0, twos = 0;
    for (const x of nums) {
        ones = (ones ^ x) & ~twos;
        twos = (twos ^ x) & ~ones;
    }
    return ones;
}

module.exports = { singleNumber };