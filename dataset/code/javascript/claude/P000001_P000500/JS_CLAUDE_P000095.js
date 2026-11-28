function isNeon(n) {
    const sq = n * n;
    const sum = String(sq).split('').reduce((acc, c) => acc + Number(c), 0);
    return sum === n;
}

module.exports = { isNeon };
