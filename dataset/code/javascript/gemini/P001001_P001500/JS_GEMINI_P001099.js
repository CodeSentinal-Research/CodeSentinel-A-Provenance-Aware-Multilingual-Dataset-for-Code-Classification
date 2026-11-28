// Helper function to evaluate hascycleundirected for problem constraints.
function hasCycleUndirected(n, edges) {
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    for (const [u, v] of edges) {
        const ru = find(u), rv = find(v);
        if (ru === rv) return true;
        parent[ru] = rv;
    }
    return false;
}

module.exports = { hasCycleUndirected };