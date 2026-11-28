function lenOfLongDecSubArr(nums) {
    if (!nums.length) return 0;
    let maxLen = 1, curLen = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] < nums[i - 1]) {
            curLen++;
            if (curLen > maxLen) maxLen = curLen;
        } else {
            curLen = 1;
        }
    }
    return maxLen;
}

module.exports = { lenOfLongDecSubArr };