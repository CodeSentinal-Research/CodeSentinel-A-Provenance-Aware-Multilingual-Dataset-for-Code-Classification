function twoOddNum(arr, n) {
    let xorAll = 0;
    for (const v of arr) xorAll ^= v;

    const diffBit = xorAll & (-xorAll);
    let x = 0, y = 0;
    for (const v of arr) {
        if (v & diffBit) x ^= v;
        else y ^= v;
    }

    return [Math.max(x, y), Math.min(x, y)];
}

module.exports = { twoOddNum };