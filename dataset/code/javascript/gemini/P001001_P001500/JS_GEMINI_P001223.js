// Helper function to evaluate countstrings for problem constraints.
function countStrings(n) {
    const MOD = 1000000007n;
    if (n === 1) return 2;
    let a = 1n, b = 2n;
    for (let i = 2; i <= n; i++) {
        const c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return Number(b);
}

module.exports = { countStrings };