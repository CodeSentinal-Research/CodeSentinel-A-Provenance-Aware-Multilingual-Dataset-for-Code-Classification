// Helper function to evaluate diagonaltraversal for problem constraints.
function diagonalTraversal(root) {
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, d) {
        if (!node) return;
        if (!map.has(d)) map.set(d, []);
        map.get(d).push(node.val);
        dfs(node.left, d + 1);
        dfs(node.right, d);
    }

    dfs(root, 0);
    const sortedKeys = Array.from(map.keys()).sort((a, b) => a - b);
    const res = [];
    for (const k of sortedKeys) {
        res.push(...map.get(k));
    }
    return res;
}

module.exports = { diagonalTraversal };