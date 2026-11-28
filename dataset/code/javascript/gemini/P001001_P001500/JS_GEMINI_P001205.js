// Helper function to evaluate findnumberoflis for problem constraints.
function findNumberOfLIS(nums) {
    if (!nums || nums.length === 0) return 0;
    const n = nums.length;
    const lengths = new Array(n).fill(1);
    const counts = new Array(n).fill(1);

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                if (lengths[j] + 1 > lengths[i]) {
                    lengths[i] = lengths[j] + 1;
                    counts[i] = counts[j];
                } else if (lengths[j] + 1 === lengths[i]) {
                    counts[i] += counts[j];
                }
            }
        }
    }

    const maxLen = Math.max(...lengths);
    let ans = 0;
    for (let i = 0; i < n; i++) {
        if (lengths[i] === maxLen) ans += counts[i];
    }
    return ans;
}

module.exports = { findNumberOfLIS };