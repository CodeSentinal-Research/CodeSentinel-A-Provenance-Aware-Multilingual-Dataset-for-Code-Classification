function lenOfLongSubarr(arr, k) {
    const map = new Map();
    let curSum = 0;
    let maxLen = 0;

    for (let i = 0; i < arr.length; i++) {
        curSum += arr[i];
        if (curSum === k) {
            maxLen = i + 1;
        } else if (map.has(curSum - k)) {
            maxLen = Math.max(maxLen, i - map.get(curSum - k));
        }
        if (!map.has(curSum)) {
            map.set(curSum, i);
        }
    }
    return maxLen;
}

module.exports = { lenOfLongSubarr };