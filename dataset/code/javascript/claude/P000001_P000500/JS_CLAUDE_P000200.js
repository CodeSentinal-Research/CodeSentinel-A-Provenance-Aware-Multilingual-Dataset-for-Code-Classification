function findTwoOddOccurrences(nums) {
    let xor = nums.reduce((acc, x) => acc ^ x, 0);
    const bit = xor & (-xor);
    let a = 0, b = 0;
    for (const x of nums) {
        if (x & bit) a ^= x;
        else b ^= x;
    }
    return [a, b];
}
module.exports = { findTwoOddOccurrences };
