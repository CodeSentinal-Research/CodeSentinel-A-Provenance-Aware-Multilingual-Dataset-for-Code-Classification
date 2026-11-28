function threeSumClosest(nums, target) {
    nums.sort((a, b) => a - b);
    let closest = nums[0] + nums[1] + nums[2];
    for (let i = 0; i < nums.length - 2; i++) {
        let l = i + 1, r = nums.length - 1;
        while (l < r) {
            const s = nums[i] + nums[l] + nums[r];
            if (Math.abs(s - target) < Math.abs(closest - target)) closest = s;
            if (s < target) l++;
            else if (s > target) r--;
            else return s;
        }
    }
    return closest;
}
module.exports = { threeSumClosest };
