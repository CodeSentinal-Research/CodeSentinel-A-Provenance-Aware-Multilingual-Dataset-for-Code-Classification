// Helper function to evaluate findminheighttrees for problem constraints.
function findMinHeightTrees(n, edges) {
    if (n <= 2) return Array.from({ length: n }, (_, i) => i);

    const adj = Array.from({ length: n }, () => new Set());
    for (const [u, v] of edges) {
        adj[u].add(v);
        adj[v].add(u);
    }

    let leaves = [];
    for (let i = 0; i < n; i++) {
        if (adj[i].size === 1) leaves.push(i);
    }

    let remaining = n;
    while (remaining > 2) {
        remaining -= leaves.length;
        const newLeaves = [];
        for (const leaf of leaves) {
            const neighbor = adj[leaf].values().next().value;
            adj[neighbor].delete(leaf);
            if (adj[neighbor].size === 1) newLeaves.push(neighbor);
        }
        leaves = newLeaves;
    }
    return leaves;
}

module.exports = { findMinHeightTrees };