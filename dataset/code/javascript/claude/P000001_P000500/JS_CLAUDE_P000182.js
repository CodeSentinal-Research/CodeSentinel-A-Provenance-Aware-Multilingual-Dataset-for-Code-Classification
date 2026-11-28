function mostFrequent(nums) {
    const cnt = new Map();
    for (const x of nums) cnt.set(x, (cnt.get(x)||0)+1);
    let best = -1, res = nums[0];
    for (const [k, v] of cnt) if (v > best) { best = v; res = k; }
    return res;
}
module.exports = { mostFrequent };
