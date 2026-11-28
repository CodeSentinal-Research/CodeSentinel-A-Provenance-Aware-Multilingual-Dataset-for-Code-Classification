function findPair(nums, target) {
    const seen = new Set();
    for (const x of nums) {
        if (seen.has(target - x)) return [target - x, x];
        seen.add(x);
    }
    return null;
}
module.exports = { findPair };
