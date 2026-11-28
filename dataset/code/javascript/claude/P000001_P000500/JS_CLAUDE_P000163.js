function findTriplet(nums, target) {
    nums = [...nums].sort((a,b) => a-b);
    for (let i = 0; i < nums.length-2; i++) {
        let l = i+1, r = nums.length-1;
        while (l < r) {
            const s = nums[i]+nums[l]+nums[r];
            if (s === target) return [nums[i], nums[l], nums[r]];
            else if (s < target) l++;
            else r--;
        }
    }
    return null;
}
module.exports = { findTriplet };
