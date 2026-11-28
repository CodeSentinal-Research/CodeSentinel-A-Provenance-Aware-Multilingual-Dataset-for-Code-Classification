function setKthBit(n, k) {
    return n | (1 << k);
}

module.exports = { setKthBit };