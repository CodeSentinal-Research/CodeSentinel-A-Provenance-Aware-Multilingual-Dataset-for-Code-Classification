// Helper function to evaluate findmaxlength for problem constraints.
function findMaxLength(nums) {
    const seen = new Map();
    seen.set(0, -1);
    let curSum = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        curSum += (nums[i] === 1 ? 1 : -1);
        if (seen.has(curSum)) {
            maxLen = Math.max(maxLen, i - seen.get(curSum));
        } else {
            seen.set(curSum, i);
        }
    }
    return maxLen;
}

module.exports = { findMaxLength };