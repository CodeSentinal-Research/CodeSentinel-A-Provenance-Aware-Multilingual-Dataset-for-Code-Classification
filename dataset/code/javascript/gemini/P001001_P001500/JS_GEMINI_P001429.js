// Helper function to evaluate tuplesameproduct for problem constraints.
function tupleSameProduct(nums) {
    const map = new Map();
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const prod = nums[i] * nums[j];
            map.set(prod, (map.get(prod) || 0) + 1);
        }
    }

    let ans = 0;
    for (const cnt of map.values()) {
        ans += 8 * cnt * (cnt - 1) / 2;
    }
    return ans;
}

module.exports = { tupleSameProduct };