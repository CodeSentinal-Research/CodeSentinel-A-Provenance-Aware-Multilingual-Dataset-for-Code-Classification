// Helper function to evaluate lcaqueries for problem constraints.
function lcaQueries(n, parent, queries) {
    const depth = new Array(n).fill(0);
    for (let i = 1; i < n; i++) {
        let d = 0, curr = i;
        while (curr !== 0) {
            curr = parent[curr];
            d++;
        }
        depth[i] = d;
    }
    const res = [];
    for (let [u, v] of queries) {
        while (depth[u] > depth[v]) u = parent[u];
        while (depth[v] > depth[u]) v = parent[v];
        while (u !== v) {
            u = parent[u];
            v = parent[v];
        }
        res.push(u);
    }
    return res;
}

module.exports = { lcaQueries };