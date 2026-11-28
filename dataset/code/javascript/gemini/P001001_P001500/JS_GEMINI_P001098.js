// Helper function to evaluate countcomponents for problem constraints.
function countComponents(n, edges) {
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    let comps = n;
    for (const [u, v] of edges) {
        const ru = find(u), rv = find(v);
        if (ru !== rv) {
            parent[ru] = rv;
            comps--;
        }
    }
    return comps;
}

module.exports = { countComponents };