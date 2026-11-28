// Helper function to evaluate countpairs for problem constraints.
function countPairs(nums, k) {
    let ans = 0;
    const n = nums.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (nums[i] === nums[j] && (i * j) % k === 0) {
                ans++;
            }
        }
    }
    return ans;
}

module.exports = { countPairs };