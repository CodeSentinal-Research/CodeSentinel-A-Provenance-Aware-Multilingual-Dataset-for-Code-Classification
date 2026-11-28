function lcmOfThree(a, b, c) {
    function gcd(x, y) {
        x = Math.abs(x); y = Math.abs(y);
        while (y !== 0) {
            const t = y; y = x % y; x = t;
        }
        return x;
    }
    function lcm(x, y) {
        if (x === 0 || y === 0) return 0;
        return (Math.abs(x) / gcd(x, y)) * Math.abs(y);
    }
    return lcm(lcm(a, b), c);
}

module.exports = { lcmOfThree };
