function maxLenEqualEvenOdd(arr) {
    const map = new Map();
    map.set(0, -1);
    let prefix = 0;
    let maxLen = 0;
    for (let i = 0; i < arr.length; i++) {
        prefix += (arr[i] % 2 === 0 ? 1 : -1);
        if (map.has(prefix)) {
            maxLen = Math.max(maxLen, i - map.get(prefix));
        } else {
            map.set(prefix, i);
        }
    }
    return maxLen;
}

module.exports = { maxLenEqualEvenOdd };