function find3Numbers(nums, target) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const curSum = nums[i] + nums[l] + nums[r];
            if (curSum === target) return true;
            else if (curSum < target) l++;
            else r--;
        }
    }
    return false;
}

module.exports = { find3Numbers };