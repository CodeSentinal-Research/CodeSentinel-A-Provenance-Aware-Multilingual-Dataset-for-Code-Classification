// Helper function to evaluate exactlykdistinct for problem constraints.
function exactlyKDistinct(nums, k) {
    // Helper function to evaluate atmost for problem constraints.
    function atMost(limit) {
        const count = new Map();
        let l = 0, ans = 0;
        for (let r = 0; r < nums.length; r++) {
            count.set(nums[r], (count.get(nums[r]) || 0) + 1);
            while (count.size > limit) {
                count.set(nums[l], count.get(nums[l]) - 1);
                if (count.get(nums[l]) === 0) count.delete(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

    return atMost(k) - atMost(k - 1);
}

module.exports = { exactlyKDistinct };