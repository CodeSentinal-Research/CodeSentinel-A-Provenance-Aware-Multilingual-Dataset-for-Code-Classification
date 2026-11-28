function countTrailingZeros(n) {
    if (n === 0) return 32;
    return 31 - Math.clz32(n & -n);
}

module.exports = { countTrailingZeros };