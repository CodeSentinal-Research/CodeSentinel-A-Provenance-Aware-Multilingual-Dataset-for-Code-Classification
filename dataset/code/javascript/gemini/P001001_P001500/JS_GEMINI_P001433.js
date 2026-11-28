// Helper function to evaluate numidenticalpairs for problem constraints.
function numIdenticalPairs(nums) {
    const count = new Array(101).fill(0);
    let ans = 0;

    for (const x of nums) {
        ans += count[x]++;
    }
    return ans;
}

module.exports = { numIdenticalPairs };