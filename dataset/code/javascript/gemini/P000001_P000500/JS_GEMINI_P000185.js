function findMaxLength(nums) {
    const map = new Map([[0, -1]]);
    let curSum = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        curSum += (nums[i] === 1 ? 1 : -1);
        if (map.has(curSum)) {
            maxLen = Math.max(maxLen, i - map.get(curSum));
        } else {
            map.set(curSum, i);
        }
    }
    return maxLen;
}

module.exports = { findMaxLength };