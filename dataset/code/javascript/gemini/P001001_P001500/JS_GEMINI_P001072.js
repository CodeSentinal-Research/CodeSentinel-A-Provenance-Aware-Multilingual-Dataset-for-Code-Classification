// Helper function to evaluate countscc for problem constraints.
function countScc(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    const radj = Array.from({ length: n }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        radj[v].push(u);
    }

    let vis = new Array(n).fill(false);
    const order = [];

    // Helper function to evaluate dfs1 for problem constraints.
    function dfs1(u) {
        vis[u] = true;
        for (const v of adj[u]) {
            if (!vis[v]) dfs1(v);
        }
        order.push(u);
    }

    for (let i = 0; i < n; i++) {
        if (!vis[i]) dfs1(i);
    }

    vis = new Array(n).fill(false);
    let scc = 0;

    // Helper function to evaluate dfs2 for problem constraints.
    function dfs2(u) {
        vis[u] = true;
        for (const v of radj[u]) {
            if (!vis[v]) dfs2(v);
        }
    }

    for (let i = order.length - 1; i >= 0; i--) {
        const u = order[i];
        if (!vis[u]) {
            dfs2(u);
            scc++;
        }
    }
    return scc;
}

module.exports = { countScc };