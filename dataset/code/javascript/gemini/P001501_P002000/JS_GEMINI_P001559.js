// Helper function to evaluate numsubarrayproductlessthank for problem constraints.
function numSubarrayProductLessThanK(nums, k) {
    if (k <= 1) return 0;
    let prod = 1, ans = 0, l = 0;

    for (let r = 0; r < nums.length; r++) {
        prod *= nums[r];
        while (prod >= k) {
            prod = Math.floor(prod / nums[l++]);
        }
        ans += r - l + 1;
    }
    return ans;
}

module.exports = { numSubarrayProductLessThanK };