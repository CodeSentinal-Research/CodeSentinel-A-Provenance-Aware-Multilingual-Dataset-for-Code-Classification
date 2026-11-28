function isDivisible(a, b) {
    if (b === 0) return false;
    return a % b === 0;
}

module.exports = { isDivisible };
