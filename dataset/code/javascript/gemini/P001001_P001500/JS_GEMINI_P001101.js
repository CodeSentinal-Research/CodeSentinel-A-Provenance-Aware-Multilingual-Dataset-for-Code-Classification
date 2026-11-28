// Helper function to evaluate findredundantconnection for problem constraints.
function findRedundantConnection(edges) {
    const n = edges.length + 1;
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    for (const [u, v] of edges) {
        const ru = find(u), rv = find(v);
        if (ru === rv) return [u, v];
        parent[ru] = rv;
    }
    return [];
}

module.exports = { findRedundantConnection };