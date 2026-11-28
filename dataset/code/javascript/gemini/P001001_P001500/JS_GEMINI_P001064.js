// Helper function to evaluate edgeexists for problem constraints.
function edgeExists(n, edges, u, v) {
    const set = new Set(edges.map(([x, y]) => `${Math.min(x, y)},${Math.max(x, y)}`));
    return set.has(`${Math.min(u, v)},${Math.max(u, v)}`);
}

module.exports = { edgeExists };