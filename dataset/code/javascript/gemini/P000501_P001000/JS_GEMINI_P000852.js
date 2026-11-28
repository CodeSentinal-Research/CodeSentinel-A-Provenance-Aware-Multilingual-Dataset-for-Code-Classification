function clearKthBit(n, k) {
    return n & ~(1 << k);
}

module.exports = { clearKthBit };