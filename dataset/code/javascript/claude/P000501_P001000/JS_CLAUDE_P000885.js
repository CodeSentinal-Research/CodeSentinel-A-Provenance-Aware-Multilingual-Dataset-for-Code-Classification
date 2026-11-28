function isArmstrong(n) {
    const digits = String(n).split('');
    const power = digits.length;
    const sum = digits.reduce((acc, d) => acc + Math.pow(parseInt(d), power), 0);
    return sum === n;
}

module.exports = { isArmstrong };
