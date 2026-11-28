// Helper function to evaluate hascycle for problem constraints.
function hasCycle(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) adj[u].push(v);

    const vis = new Array(n).fill(0);
    // Helper function to evaluate dfs for problem constraints.
    function dfs(u) {
        vis[u] = 1;
        for (const v of adj[u]) {
            if (vis[v] === 1) return true;
            if (vis[v] === 0 && dfs(v)) return true;
        }
        vis[u] = 2;
        return false;
    }

    for (let i = 0; i < n; i++) {
        if (vis[i] === 0 && dfs(i)) return true;
    }
    return false;
}

module.exports = { hasCycle };