// Helper function to evaluate countbadpairs for problem constraints.
function countBadPairs(nums) {
    const n = BigInt(nums.length);
    const totalPairs = n * (n - 1n) / 2n;
    const map = new Map();

    for (let i = 0; i < nums.length; i++) {
        const diff = nums[i] - i;
        map.set(diff, (map.get(diff) || 0n) + 1n);
    }

    let goodPairs = 0n;
    for (const cnt of map.values()) {
        goodPairs += cnt * (cnt - 1n) / 2n;
    }
    return Number(totalPairs - goodPairs);
}

module.exports = { countBadPairs };