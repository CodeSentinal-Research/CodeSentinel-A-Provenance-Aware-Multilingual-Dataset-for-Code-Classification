function isValidTriangle(a, b, c) {
    return a + b > c && a + c > b && b + c > a;
}

module.exports = { isValidTriangle };
