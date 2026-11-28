function firstRepeating(nums) {
    const seen = new Set();
    for (const x of nums) {
        if (seen.has(x)) return x;
        seen.add(x);
    }
    return -1;
}
module.exports = { firstRepeating };
