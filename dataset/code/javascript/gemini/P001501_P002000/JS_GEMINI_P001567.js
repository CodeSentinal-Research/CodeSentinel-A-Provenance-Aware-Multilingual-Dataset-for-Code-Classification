// Helper function to evaluate countcompletesubarrays for problem constraints.
function countCompleteSubarrays(nums) {
    const k = new Set(nums).size;
    const count = new Map();
    let ans = 0, l = 0;

    for (let r = 0; r < nums.length; r++) {
        count.set(nums[r], (count.get(nums[r]) || 0) + 1);
        while (count.size === k) {
            ans += nums.length - r;
            count.set(nums[l], count.get(nums[l]) - 1);
            if (count.get(nums[l]) === 0) count.delete(nums[l]);
            l++;
        }
    }
    return ans;
}

module.exports = { countCompleteSubarrays };