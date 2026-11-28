// Helper function to evaluate diagonalsum for problem constraints.
function diagonalSum(root) {
    if (!root) return [];
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, d) {
        if (!node) return;
        map.set(d, (map.get(d) || 0) + node.val);
        dfs(node.left, d + 1);
        dfs(node.right, d);
    }

    dfs(root, 0);
    const sortedKeys = Array.from(map.keys()).sort((a, b) => a - b);
    return sortedKeys.map(k => map.get(k));
}

module.exports = { diagonalSum };