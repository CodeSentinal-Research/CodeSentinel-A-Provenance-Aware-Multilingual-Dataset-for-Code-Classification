// Helper function to evaluate findneighbors for problem constraints.
function findNeighbors(n, edges, target) {
    const res = [];
    for (const [u, v] of edges) {
        if (u === target) res.push(v);
        else if (v === target) res.push(u);
    }
    return res.sort((a, b) => a - b);
}

module.exports = { findNeighbors };