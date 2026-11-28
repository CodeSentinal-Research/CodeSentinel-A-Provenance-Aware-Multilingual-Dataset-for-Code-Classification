function countPairs(nums, target) {
    const map = new Map();
    let count = 0;
    for (const x of nums) {
        count += (map.get(target - x) || 0);
        map.set(x, (map.get(x) || 0) + 1);
    }
    return count;
}

module.exports = { countPairs };