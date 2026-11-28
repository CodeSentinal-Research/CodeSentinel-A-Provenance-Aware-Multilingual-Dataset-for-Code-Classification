function threeSumClosest(nums, target) {
    nums.sort((a, b) => a - b);
    let closest = nums[0] + nums[1] + nums[2];
    const n = nums.length;

    for (let i = 0; i < n - 2; i++) {
        let l = i + 1, r = n - 1;
        while (l < r) {
            const curSum = nums[i] + nums[l] + nums[r];
            if (Math.abs(curSum - target) < Math.abs(closest - target)) {
                closest = curSum;
            }
            if (curSum < target) l++;
            else if (curSum > target) r--;
            else return target;
        }
    }
    return closest;
}

module.exports = { threeSumClosest };