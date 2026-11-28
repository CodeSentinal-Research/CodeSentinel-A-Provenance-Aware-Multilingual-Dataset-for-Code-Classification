// Helper function to evaluate ishappy for problem constraints.
function isHappy(n) {
    const seen = new Set();
    while (n !== 1 && !seen.has(n)) {
        seen.add(n);
        let sum = 0;
        while (n > 0) {
            const d = n % 10;
            sum += d * d;
            n = Math.floor(n / 10);
        }
        n = sum;
    }
    return n === 1;
}

module.exports = { isHappy };