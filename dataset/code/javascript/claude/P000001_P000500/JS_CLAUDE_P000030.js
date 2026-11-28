function lcm(a, b) {
    if (a === 0 || b === 0) return 0;
    function gcd(x, y) {
        x = Math.abs(x);
        y = Math.abs(y);
        while (y !== 0) {
            const t = y;
            y = x % y;
            x = t;
        }
        return x;
    }
    return (Math.abs(a) / gcd(a, b)) * Math.abs(b);
}

module.exports = { lcm };
