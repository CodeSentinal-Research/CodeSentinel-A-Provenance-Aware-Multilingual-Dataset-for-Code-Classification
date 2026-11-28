// Helper function to evaluate countequalzerosones for problem constraints.
function countEqualZerosOnes(nums) {
    const count = new Map();
    count.set(0, 1);
    let curSum = 0, ans = 0;

    for (const x of nums) {
        curSum += (x === 1 ? 1 : -1);
        ans += (count.get(curSum) || 0);
        count.set(curSum, (count.get(curSum) || 0) + 1);
    }
    return ans;
}

module.exports = { countEqualZerosOnes };