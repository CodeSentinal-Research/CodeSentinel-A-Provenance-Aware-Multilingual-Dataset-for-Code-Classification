// Helper function to evaluate jump for problem constraints.
function jump(nums) {
    let jumps = 0;
    let curEnd = 0, curFarthest = 0;

    for (let i = 0; i < nums.length - 1; i++) {
        curFarthest = Math.max(curFarthest, i + nums[i]);
        if (i === curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}

module.exports = { jump };