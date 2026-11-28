// Helper function to evaluate criticalconnections for problem constraints.
function criticalConnections(n, connections) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of connections) {
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
                    bridges.push([u, v]);
                }
            }
        }
    }

    dfs(0);
    return bridges;
}

module.exports = { criticalConnections };