// Helper function to evaluate phi for problem constraints.
function phi(n) {
    let result = n;
    let p = 2;
    while (p * p <= n) {
        if (n % p === 0) {
            while (n % p === 0) n = Math.floor(n / p);
            result -= Math.floor(result / p);
        }
        p++;
    }
    if (n > 1) result -= Math.floor(result / n);
    return result;
}

module.exports = { phi };