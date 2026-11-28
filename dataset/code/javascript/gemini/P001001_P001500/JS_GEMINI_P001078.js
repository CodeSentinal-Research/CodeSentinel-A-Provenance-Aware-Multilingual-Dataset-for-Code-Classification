// Helper function to evaluate primmst for problem constraints.
function primMst(n, edges) {
    const adj = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        adj[u].push([v, w]);
        adj[v].push([u, w]);
    }
    const vis = new Array(n).fill(false);
    const key = new Array(n).fill(Infinity);
    key[0] = 0;
    let total = 0;

    for (let iter = 0; iter < n; iter++) {
        let u = -1;
        for (let i = 0; i < n; i++) {
            if (!vis[i] && (u === -1 || key[i] < key[u])) {
                u = i;
            }
        }
        if (u === -1 || key[u] === Infinity) break;
        vis[u] = true;
        total += key[u];
        for (const [v, w] of adj[u]) {
            if (!vis[v] && w < key[v]) {
                key[v] = w;
            }
        }
    }
    return total;
}

module.exports = { primMst };