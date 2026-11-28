function firstRepeated(arr) {
    const freq = new Map();
    for (const x of arr) freq.set(x, (freq.get(x) || 0) + 1);
    for (let i = 0; i < arr.length; i++) {
        if (freq.get(arr[i]) > 1) return i + 1;
    }
    return -1;
}

module.exports = { firstRepeated };