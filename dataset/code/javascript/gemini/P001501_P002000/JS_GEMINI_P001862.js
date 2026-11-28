// Helper function to evaluate optimalroot for problem constraints.
function optimalRoot(keys, freq) {
    const n = keys.length;
    const cost = Array.from({ length: n }, () => new Array(n).fill(0));
    const rootChoice = Array.from({ length: n }, () => new Array(n).fill(0));
    const w = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        w[i][i] = freq[i];
        cost[i][i] = freq[i];
        rootChoice[i][i] = i;
        for (let j = i + 1; j < n; j++) {
            w[i][j] = w[i][j - 1] + freq[j];
        }
    }

    for (let len = 2; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            cost[i][j] = Infinity;
            for (let r = i; r <= j; r++) {
                const c = (r > i ? cost[i][r - 1] : 0) + (r < j ? cost[r + 1][j] : 0) + w[i][j];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    rootChoice[i][j] = r;
                }
            }
        }
    }
    return keys[rootChoice[0][n - 1]];
}

module.exports = { optimalRoot };