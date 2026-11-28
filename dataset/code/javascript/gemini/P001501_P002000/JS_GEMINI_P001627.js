// Helper function to evaluate countprefixesdivisiblebyk for problem constraints.
function countPrefixesDivisibleByK(nums, k) {
    let cur = 0, ans = 0;
    for (const x of nums) {
        cur += x;
        if (cur % k === 0) ans++;
    }
    return ans;
}

module.exports = { countPrefixesDivisibleByK };