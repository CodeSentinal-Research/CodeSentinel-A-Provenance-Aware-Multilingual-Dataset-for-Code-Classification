function isKthBitSet(n, k) {
    return (n & (1 << k)) !== 0;
}

module.exports = { isKthBitSet };