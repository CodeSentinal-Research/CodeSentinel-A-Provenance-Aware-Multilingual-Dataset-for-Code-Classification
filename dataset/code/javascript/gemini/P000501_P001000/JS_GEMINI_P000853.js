function toggleKthBit(n, k) {
    return n ^ (1 << k);
}

module.exports = { toggleKthBit };