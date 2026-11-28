// Helper function to evaluate dynamicconnectivity for problem constraints.
function dynamicConnectivity(n, queries) {
    const parent = Array.from({ length: n }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    const res = [];
    for (const [type, u, v] of queries) {
        if (type === 1) {
            const ru = find(u), rv = find(v);
            if (ru !== rv) parent[ru] = rv;
        } else {
            res.push(find(u) === find(v) ? 'YES' : 'NO');
        }
    }
    return res;
}

module.exports = { dynamicConnectivity };