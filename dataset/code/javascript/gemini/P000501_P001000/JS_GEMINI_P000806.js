function maxLenEqualPosNeg(arr) {
    const map = new Map();
    map.set(0, -1);
    let prefixSum = 0;
    let maxLen = 0;
    for (let i = 0; i < arr.length; i++) {
        const val = arr[i] > 0 ? 1 : (arr[i] < 0 ? -1 : 0);
        prefixSum += val;
        if (map.has(prefixSum)) {
            maxLen = Math.max(maxLen, i - map.get(prefixSum));
        } else {
            map.set(prefixSum, i);
        }
    }
    return maxLen;
}

module.exports = { maxLenEqualPosNeg };