function isArmstrong(n) {
    if (n < 0) return false;
    const s = String(n);
    const k = s.length;
    const sum = s.split('').reduce((acc, c) => acc + Math.pow(Number(c), k), 0);
    return sum === n;
}

module.exports = { isArmstrong };
