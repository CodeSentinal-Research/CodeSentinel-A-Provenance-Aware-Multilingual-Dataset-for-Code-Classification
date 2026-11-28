// Helper function to evaluate stonegameii for problem constraints.
function stoneGameII(piles) {
    const n = piles.length;
    const suffix = new Array(n + 1).fill(0);
    for (let i = n - 1; i >= 0; i--) suffix[i] = suffix[i + 1] + piles[i];

    const memo = Array.from({ length: n + 1 }, () => new Array(n + 1).fill(0));

    // Helper function to evaluate dp for problem constraints.
    function dp(i, m) {
        if (i >= n) return 0;
        if (i + 2 * m >= n) return suffix[i];
        if (memo[i][m] > 0) return memo[i][m];

        let res = 0;
        for (let x = 1; x <= 2 * m; x++) {
            res = Math.max(res, suffix[i] - dp(i + x, Math.max(m, x)));
        }
        return memo[i][m] = res;
    }

    return dp(0, 1);
}

module.exports = { stoneGameII };