// Helper function to evaluate numways for problem constraints.
function numWays(n, k) {
    if (n === 0) return 0;
    if (n === 1) return k;
    let same = k;
    let diff = k * (k - 1);
    for (let i = 3; i <= n; i++) {
        const newSame = diff;
        const newDiff = (same + diff) * (k - 1);
        same = newSame;
        diff = newDiff;
    }
    return same + diff;
}

module.exports = { numWays };