// Helper function to evaluate constructobst for problem constraints.
function constructOBST(keys, freq) {
    const n = keys.length;
    const cost = Array.from({ length: n }, () => new Array(n).fill(0));
    const rootIdx = Array.from({ length: n }, () => new Array(n).fill(0));
    const w = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        w[i][i] = freq[i];
        cost[i][i] = freq[i];
        rootIdx[i][i] = i;
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
                    rootIdx[i][j] = r;
                }
            }
        }
    }

    // Helper function to evaluate build for problem constraints.
    function build(i, j) {
        if (i > j) return null;
        const r = rootIdx[i][j];
        const node = { val: keys[r], left: null, right: null };
        node.left = build(i, r - 1);
        node.right = build(r + 1, j);
        return node;
    }

    return build(0, n - 1);
}

module.exports = { constructOBST };