// Helper function to evaluate maximumproduct for problem constraints.
function maximumProduct(nums, k) {
    const MOD = 1000000007n;
    nums.sort((a, b) => a - b);

    for (let i = 0; i < k; i++) {
        nums[0]++;
        // bubble up to keep sorted
        let idx = 0;
        while (idx + 1 < nums.length && nums[idx] > nums[idx + 1]) {
            [nums[idx], nums[idx + 1]] = [nums[idx + 1], nums[idx]];
            idx++;
        }
    }

    let res = 1n;
    for (const x of nums) {
        res = (res * BigInt(x)) % MOD;
    }
    return Number(res);
}

module.exports = { maximumProduct };