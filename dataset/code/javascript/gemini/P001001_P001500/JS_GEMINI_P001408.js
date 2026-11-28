// Helper function to evaluate recoverarray for problem constraints.
function recoverArray(nums) {
    nums.sort((a, b) => a - b);
    const n = Math.floor(nums.length / 2);

    for (let i = 1; i < nums.length; i++) {
        const diff = nums[i] - nums[0];
        if (diff <= 0 || diff % 2 !== 0) continue;
        const k = Math.floor(diff / 2);

        const map = new Map();
        for (const x of nums) map.set(x, (map.get(x) || 0) + 1);

        const res = [];
        for (const x of nums) {
            if ((map.get(x) || 0) === 0) continue;
            if ((map.get(x + 2 * k) || 0) === 0) break;

            res.push(x + k);
            map.set(x, map.get(x) - 1);
            map.set(x + 2 * k, map.get(x + 2 * k) - 1);
        }

        if (res.length === n) return res;
    }
    return [];
}

module.exports = { recoverArray };