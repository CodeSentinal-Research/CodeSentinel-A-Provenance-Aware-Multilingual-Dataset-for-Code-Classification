function firstNonRepeating(nums) {
    const cnt = new Map();
    for (const x of nums) cnt.set(x, (cnt.get(x)||0)+1);
    for (const x of nums) if (cnt.get(x) === 1) return x;
    return -1;
}
module.exports = { firstNonRepeating };
