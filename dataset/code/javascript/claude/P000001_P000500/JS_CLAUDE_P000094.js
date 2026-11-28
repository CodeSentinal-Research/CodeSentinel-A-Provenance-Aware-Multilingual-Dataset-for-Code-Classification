function isHarshad(n) {
    if (n <= 0) return false;
    const sum = String(n).split('').reduce((acc, c) => acc + Number(c), 0);
    return n % sum === 0;
}

module.exports = { isHarshad };
