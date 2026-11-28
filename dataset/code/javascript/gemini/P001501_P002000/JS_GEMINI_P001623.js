// Helper function to evaluate countnegativeprefixes for problem constraints.
function countNegativePrefixes(nums) {
    let cur = 0, ans = 0;
    for (const x of nums) {
        cur += x;
        if (cur < 0) ans++;
    }
    return ans;
}

module.exports = { countNegativePrefixes };