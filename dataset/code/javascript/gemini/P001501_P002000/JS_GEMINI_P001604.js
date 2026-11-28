// Helper function to evaluate subarraysum for problem constraints.
function subarraySum(nums, k) {
    const count = new Map();
    count.set(0, 1);
    let curSum = 0, ans = 0;

    for (const x of nums) {
        curSum += x;
        ans += (count.get(curSum - k) || 0);
        count.set(curSum, (count.get(curSum) || 0) + 1);
    }
    return ans;
}

module.exports = { subarraySum };