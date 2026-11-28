// Helper function to evaluate windowaverages for problem constraints.
function windowAverages(nums, k) {
    if (nums.length < k) return [];
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    const res = [curSum / k];

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        res.push(curSum / k);
    }
    return res;
}

module.exports = { windowAverages };