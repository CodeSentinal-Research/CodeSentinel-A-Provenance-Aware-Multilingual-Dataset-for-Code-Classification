// Helper function to evaluate kruskalmst for problem constraints.
function kruskalMst(n, edges) {
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    edges.sort((a, b) => {
        if (a[2] !== b[2]) return a[2] - b[2];
        const mina = Math.min(a[0], a[1]), minb = Math.min(b[0], b[1]);
        if (mina !== minb) return mina - minb;
        return Math.max(a[0], a[1]) - Math.max(b[0], b[1]);
    });
    const mst = [];
    for (const [u, v, w] of edges) {
        const ru = find(u), rv = find(v);
        if (ru !== rv) {
            parent[ru] = rv;
            mst.push([Math.min(u, v), Math.max(u, v), w]);
            if (mst.length === n - 1) break;
        }
    }
    return mst;
}

module.exports = { kruskalMst };