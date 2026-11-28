// Helper function to evaluate countderangements for problem constraints.
function countDerangements(n) {
    const MOD = 1000000007n;
    if (n === 1) return 0;
    if (n === 2) return 1;
    let a = 0n, b = 1n;
    for (let i = 3n; i <= BigInt(n); i++) {
        const c = ((i - 1n) * (a + b)) % MOD;
        a = b;
        b = c;
    }
    return Number(b);
}

module.exports = { countDerangements };