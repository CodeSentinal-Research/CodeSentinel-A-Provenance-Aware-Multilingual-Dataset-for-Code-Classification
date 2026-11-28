function findLeaders(nums) {
    if (!nums.length) return [];
    const leaders = [nums[nums.length - 1]];
    let maxRight = nums[nums.length - 1];
    for (let i = nums.length - 2; i >= 0; i--) {
        if (nums[i] >= maxRight) { maxRight = nums[i]; leaders.push(maxRight); }
    }
    return leaders.reverse();
}
module.exports = { findLeaders };
