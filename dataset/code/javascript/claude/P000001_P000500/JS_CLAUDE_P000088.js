function isPerfectSquare(num) {
    if (num < 0) return false;
    const r = Math.floor(Math.sqrt(num));
    return r * r === num;
}

module.exports = { isPerfectSquare };
