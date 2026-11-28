// Helper function to evaluate atmostkdistinct for problem constraints.
function atMostKDistinct(nums, k) {
    const count = new Map();
    let l = 0, ans = 0;

    for (let r = 0; r < nums.length; r++) {
        count.set(nums[r], (count.get(nums[r]) || 0) + 1);
        while (count.size > k) {
            const left = nums[l++];
            count.set(left, count.get(left) - 1);
            if (count.get(left) === 0) count.delete(left);
        }
        ans += r - l + 1;
    }
    return ans;
}

module.exports = { atMostKDistinct };