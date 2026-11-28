// Helper function to evaluate verticalsum for problem constraints.
function verticalSum(root) {
    if (!root) return [];
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, col) {
        if (!node) return;
        map.set(col, (map.get(col) || 0) + node.val);
        dfs(node.left, col - 1);
        dfs(node.right, col + 1);
    }

    dfs(root, 0);
    const sortedKeys = Array.from(map.keys()).sort((a, b) => a - b);
    return sortedKeys.map(k => map.get(k));
}

module.exports = { verticalSum };