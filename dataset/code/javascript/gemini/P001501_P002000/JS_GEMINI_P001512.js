// Helper function to evaluate numsubarrayswithsum for problem constraints.
function numSubarraysWithSum(nums, goal) {
    const count = new Map();
    count.set(0, 1);
    let curSum = 0, ans = 0;

    for (const x of nums) {
        curSum += x;
        ans += (count.get(curSum - goal) || 0);
        count.set(curSum, (count.get(curSum) || 0) + 1);
    }
    return ans;
}

module.exports = { numSubarraysWithSum };