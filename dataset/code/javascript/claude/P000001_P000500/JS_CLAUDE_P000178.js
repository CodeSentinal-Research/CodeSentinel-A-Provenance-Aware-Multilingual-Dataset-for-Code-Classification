function frequencySort(nums) {
    const cnt = new Map();
    for (const x of nums) cnt.set(x, (cnt.get(x)||0)+1);
    return [...nums].sort((a, b) => cnt.get(b) !== cnt.get(a) ? cnt.get(b) - cnt.get(a) : a - b);
}
module.exports = { frequencySort };
