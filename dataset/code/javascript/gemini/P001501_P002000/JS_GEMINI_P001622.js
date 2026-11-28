// Helper function to evaluate countpositiveprefixes for problem constraints.
function countPositivePrefixes(nums) {
    let cur = 0, ans = 0;
    for (const x of nums) {
        cur += x;
        if (cur > 0) ans++;
    }
    return ans;
}

module.exports = { countPositivePrefixes };