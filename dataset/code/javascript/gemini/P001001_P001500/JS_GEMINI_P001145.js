// Helper function to evaluate longestbitonicsubsequence for problem constraints.
function longestBitonicSubsequence(nums) {
    const n = nums.length;
    if (n === 0) return 0;
    const inc = new Array(n).fill(1);
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[j] < nums[i]) inc[i] = Math.max(inc[i], inc[j] + 1);
        }
    }

    const dec = new Array(n).fill(1);
    for (let i = n - 1; i >= 0; i--) {
        for (let j = n - 1; j > i; j--) {
            if (nums[j] < nums[i]) dec[i] = Math.max(dec[i], dec[j] + 1);
        }
    }

    let ans = 0;
    for (let i = 0; i < n; i++) {
        ans = Math.max(ans, inc[i] + dec[i] - 1);
    }
    return ans;
}

module.exports = { longestBitonicSubsequence };