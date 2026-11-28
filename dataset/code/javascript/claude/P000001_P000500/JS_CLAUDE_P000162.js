function countPairsWithSum(nums, target) {
    const cnt = new Map();
    for (const x of nums) cnt.set(x, (cnt.get(x)||0)+1);
    let count = 0;
    const visited = new Set();
    for (const [x, cx] of cnt) {
        const y = target - x;
        if (cnt.has(y) && !visited.has(y)) {
            count += x === y ? cx*(cx-1)/2 : cx*cnt.get(y);
            visited.add(x);
        }
    }
    return count;
}
module.exports = { countPairsWithSum };
