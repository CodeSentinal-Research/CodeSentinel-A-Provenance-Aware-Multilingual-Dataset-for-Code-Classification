function findOddOccurrence(nums) {
    return nums.reduce((acc, x) => acc ^ x, 0);
}
module.exports = { findOddOccurrence };
