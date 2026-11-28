// Helper function to evaluate foursum for problem constraints.
function fourSum(nums, target) {
    nums.sort((a, b) => a - b);
    const res = [];
    const n = nums.length;
    const tgt = BigInt(target);

    for (let i = 0; i < n - 3; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) continue;
        for (let j = i + 1; j < n - 2; j++) {
            if (j > i + 1 && nums[j] === nums[j - 1]) continue;
            let l = j + 1, r = n - 1;
            while (l < r) {
                const sum = BigInt(nums[i]) + BigInt(nums[j]) + BigInt(nums[l]) + BigInt(nums[r]);
                if (sum === tgt) {
                    res.push([nums[i], nums[j], nums[l], nums[r]]);
                    while (l < r && nums[l] === nums[l + 1]) l++;
                    while (l < r && nums[r] === nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < tgt) {
                    l++;
                } else {
                    r--;
                }
            }
        }
    }
    return res;
}

module.exports = { fourSum };