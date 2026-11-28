function chocolateDistribution(nums, m) {
    if (m === 0 || !nums.length) return 0;
    nums = [...nums].sort((a, b) => a - b);
    const n = nums.length;
    if (m > n) return -1;
    let minDiff = Infinity;
    for (let i = 0; i <= n - m; i++)
        minDiff = Math.min(minDiff, nums[i + m - 1] - nums[i]);
    return minDiff;
}
module.exports = { chocolateDistribution };
