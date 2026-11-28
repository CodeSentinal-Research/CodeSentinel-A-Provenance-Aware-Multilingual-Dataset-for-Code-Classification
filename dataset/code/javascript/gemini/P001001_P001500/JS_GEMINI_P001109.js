// Helper function to evaluate verifycoloring for problem constraints.
function verifyColoring(n, edges, colors) {
    for (const [u, v] of edges) {
        if (colors[u] === colors[v]) return false;
    }
    return true;
}

module.exports = { verifyColoring };