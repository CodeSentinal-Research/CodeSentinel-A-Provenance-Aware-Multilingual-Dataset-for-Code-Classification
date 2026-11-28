function findAllPairs(nums, target) {
    const cnt = new Map();
    for (const x of nums) cnt.set(x, (cnt.get(x) || 0) + 1);
    const res = [], seen = new Set();
    for (const x of nums) {
        const y = target - x;
        const key = Math.min(x, y) + '_' + Math.max(x, y);
        if (cnt.has(y) && !seen.has(key)) {
            if (x !== y || cnt.get(x) >= 2) res.push([Math.min(x,y), Math.max(x,y)]);
            seen.add(key);
        }
    }
    return res;
}
module.exports = { findAllPairs };
