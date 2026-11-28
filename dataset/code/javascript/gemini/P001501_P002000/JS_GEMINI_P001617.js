// Helper function to evaluate countevensumprefixes for problem constraints.
function countEvenSumPrefixes(nums) {
    let cur = 0, ans = 0;
    for (const x of nums) {
        cur += x;
        if (cur % 2 === 0) ans++;
    }
    return ans;
}

module.exports = { countEvenSumPrefixes };