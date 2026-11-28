// Helper function to evaluate countkdifference for problem constraints.
function countKDifference(nums, k) {
    const count = new Map();
    let ans = 0;

    for (const x of nums) {
        ans += (count.get(x - k) || 0) + (count.get(x + k) || 0);
        count.set(x, (count.get(x) || 0) + 1);
    }
    return ans;
}

module.exports = { countKDifference };