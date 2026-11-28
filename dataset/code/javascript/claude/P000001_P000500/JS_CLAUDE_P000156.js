function findMaxConsecutiveZeros(nums) {
    let best = 0, cur = 0;
    for (const x of nums) {
        cur = x === 0 ? cur + 1 : 0;
        best = Math.max(best, cur);
    }
    return best;
}
module.exports = { findMaxConsecutiveZeros };
