// Helper function to evaluate findmothervertex for problem constraints.
function findMotherVertex(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) adj[u].push(v);

    let vis = new Array(n).fill(false);
    let lastV = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(u) {
        vis[u] = true;
        for (const v of adj[u]) {
            if (!vis[v]) dfs(v);
        }
    }

    for (let i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
            lastV = i;
        }
    }

    vis = new Array(n).fill(false);
    dfs(lastV);
    return vis.every(Boolean) ? lastV : -1;
}

module.exports = { findMotherVertex };