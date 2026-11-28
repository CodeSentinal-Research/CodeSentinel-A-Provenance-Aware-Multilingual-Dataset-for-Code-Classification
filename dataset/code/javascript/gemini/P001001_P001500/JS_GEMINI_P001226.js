// Helper function to evaluate countfriendspairings for problem constraints.
function countFriendsPairings(n) {
    const MOD = 1000000007n;
    if (n <= 2) return n;
    let a = 1n, b = 2n;
    for (let i = 3n; i <= BigInt(n); i++) {
        const c = (b + (i - 1n) * a) % MOD;
        a = b;
        b = c;
    }
    return Number(b);
}

module.exports = { countFriendsPairings };