function rearrangeAlternately(nums) {
    nums = [...nums].sort((a, b) => a - b);
    const res = [], n = nums.length;
    let l = 0, r = n - 1, toggle = true;
    while (l <= r) {
        if (toggle) res.push(nums[r--]);
        else res.push(nums[l++]);
        toggle = !toggle;
    }
    return res;
}
module.exports = { rearrangeAlternately };
