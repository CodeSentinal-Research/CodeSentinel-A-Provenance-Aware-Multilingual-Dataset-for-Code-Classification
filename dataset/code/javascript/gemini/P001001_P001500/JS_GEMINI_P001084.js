// Helper function to evaluate hashamiltoniancycle for problem constraints.
function hasHamiltonianCycle(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }
    const vis = new Array(n).fill(false);

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u, count) {
        if (count === n) return adj[u].includes(0);
        vis[u] = true;
        for (const v of adj[u]) {
            if (!vis[v] && dfs(v, count + 1)) return true;
        }
        vis[u] = false;
        return false;
    }

    return dfs(0, 1);
}

module.exports = { hasHamiltonianCycle };