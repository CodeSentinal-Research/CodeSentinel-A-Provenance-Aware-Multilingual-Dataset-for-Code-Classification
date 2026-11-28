// Helper function to evaluate findarticulationpoints for problem constraints.
function findArticulationPoints(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const tin = new Array(n).fill(-1);
    const low = new Array(n).fill(-1);
    const isAp = new Array(n).fill(false);
    let timer = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u, p = -1) {
        tin[u] = low[u] = timer++;
        let children = 0;
        for (const v of adj[u]) {
            if (v === p) continue;
            if (tin[v] !== -1) {
                low[u] = Math.min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] >= tin[u] && p !== -1) isAp[u] = true;
                children++;
            }
        }
        if (p === -1 && children > 1) isAp[u] = true;
    }

    for (let i = 0; i < n; i++) {
        if (tin[i] === -1) dfs(i);
    }
    const res = [];
    for (let i = 0; i < n; i++) {
        if (isAp[i]) res.push(i);
    }
    return res;
}

module.exports = { findArticulationPoints };