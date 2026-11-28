// Helper function to evaluate integerbreak for problem constraints.
function integerBreak(n) {
    if (n <= 3) return n - 1;
    let prod = 1;
    while (n > 4) {
        prod *= 3;
        n -= 3;
    }
    return prod * n;
}

module.exports = { integerBreak };