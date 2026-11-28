function findMissingRepeating(nums) {
    const n = nums.length;
    const cnt = new Array(n + 1).fill(0);
    let rep = -1, miss = -1;
    for (const x of nums) { cnt[x]++; if (cnt[x] === 2) rep = x; }
    for (let i = 1; i <= n; i++) if (cnt[i] === 0) { miss = i; break; }
    return [rep, miss];
}
module.exports = { findMissingRepeating };
