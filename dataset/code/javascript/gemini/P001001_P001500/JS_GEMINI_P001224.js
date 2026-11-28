// Helper function to evaluate countwaystile for problem constraints.
function countWaysTile(n) {
    const MOD = 1000000007n;
    if (n <= 2) return n;
    let a = 1n, b = 2n;
    for (let i = 3; i <= n; i++) {
        const c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return Number(b);
}

module.exports = { countWaysTile };