// Helper function to evaluate numsubseq for problem constraints.
function numSubseq(nums, target) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const MOD = 1000000007n;

    const power = new Array(n);
    power[0] = 1n;
    for (let i = 1; i < n; i++) {
        power[i] = (power[i - 1] * 2n) % MOD;
    }

    let l = 0, r = n - 1;
    let ans = 0n;

    // Binary search loop to narrow down range
    while (l <= r) {
        if (nums[l] + nums[r] <= target) {
            ans = (ans + power[r - l]) % MOD;
            l++;
        } else {
            r--;
        }
    }
    return Number(ans);
}

module.exports = { numSubseq };