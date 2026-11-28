// Performs search to locate target element within the given collection.
function optimalSearchTree(p, q, n) {
    const e = Array.from({ length: n + 2 }, () => new Array(n + 2).fill(0));
    const w = Array.from({ length: n + 2 }, () => new Array(n + 2).fill(0));

    for (let i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (let len = 1; len <= n; len++) {
        for (let i = 1; i <= n - len + 1; i++) {
            const j = i + len - 1;
            e[i][j] = Infinity;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];
            for (let r = i; r <= j; r++) {
                const t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                }
            }
        }
    }
    return e[1][n];
}

module.exports = { optimalSearchTree };