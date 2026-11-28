// Helper function to evaluate mstweight for problem constraints.
function mstWeight(n, edges) {
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    edges.sort((a, b) => a[2] - b[2]);
    let total = 0, count = 0;
    for (const [u, v, w] of edges) {
        const ru = find(u), rv = find(v);
        if (ru !== rv) {
            parent[ru] = rv;
            total += w;
            if (++count === n - 1) break;
        }
    }
    return total;
}

module.exports = { mstWeight };