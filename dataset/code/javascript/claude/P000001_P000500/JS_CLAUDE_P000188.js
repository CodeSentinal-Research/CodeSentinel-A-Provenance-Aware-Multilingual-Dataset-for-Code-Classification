function subarrayWithGivenSum(nums, target) {
    let l = 0, cur = 0;
    for (let r = 0; r < nums.length; r++) {
        cur += nums[r];
        while (cur > target && l <= r) cur -= nums[l++];
        if (cur === target) return [l, r];
    }
    return null;
}
module.exports = { subarrayWithGivenSum };
