// Helper function to evaluate findbridges for problem constraints.
function findBridges(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const tin = new Array(n).fill(-1);
    const low = new Array(n).fill(-1);
    let timer = 0;
    const bridges = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u, p = -1) {
        tin[u] = low[u] = timer++;
        for (const v of adj[u]) {
            if (v === p) continue;
            if (tin[v] !== -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    bridges.push([Math.min(u, v), Math.max(u, v)]);
                }
            }
        }
    }

    for (let i = 0; i < n; i++) {
        if (tin[i] === -1) dfs(i);
    }
    return bridges.sort((a, b) => a[0] !== b[0] ? a[0] - b[0] : a[1] - b[1]);
}

module.exports = { findBridges };