// Helper function to evaluate mincostconnectcities for problem constraints.
function minCostConnectCities(n, connections) {
    const parent = Array.from({ length: n + 1 }, (_, i) => i);
    // Helper function to evaluate find for problem constraints.
    function find(i) {
        if (parent[i] === i) return i;
        return parent[i] = find(parent[i]);
    }
    connections.sort((a, b) => a[2] - b[2]);
    let total = 0, count = 0;
    for (const [u, v, cost] of connections) {
        const ru = find(u), rv = find(v);
        if (ru !== rv) {
            parent[ru] = rv;
            total += cost;
            if (++count === n - 1) return total;
        }
    }
    return count === n - 1 ? total : -1;
}

module.exports = { minCostConnectCities };