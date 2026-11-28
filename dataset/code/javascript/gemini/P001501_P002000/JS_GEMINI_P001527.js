// Helper function to evaluate minimumsumsubarray for problem constraints.
function minimumSumSubarray(nums, l, r) {
    const n = nums.length;
    const prefix = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];

    let ans = Infinity;
    for (let size = l; size <= r; size++) {
        for (let i = 0; i <= n - size; i++) {
            const sum = prefix[i + size] - prefix[i];
            if (sum > 0) ans = Math.min(ans, sum);
        }
    }
    return ans !== Infinity ? ans : -1;
}

module.exports = { minimumSumSubarray };