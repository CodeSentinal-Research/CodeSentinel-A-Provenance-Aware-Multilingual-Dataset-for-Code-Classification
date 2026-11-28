// Helper function to evaluate clonegraph for problem constraints.
function cloneGraph(node) {
    if (!node) return null;
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(curr) {
        if (map.has(curr)) return map.get(curr);
        const clone = { val: curr.val, neighbors: [] };
        map.set(curr, clone);
        for (const nbr of curr.neighbors) {
            clone.neighbors.push(dfs(nbr));
        }
        return clone;
    }

    return dfs(node);
}

module.exports = { cloneGraph };