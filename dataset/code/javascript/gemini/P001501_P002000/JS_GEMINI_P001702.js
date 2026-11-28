// Helper function to evaluate goodnodes for problem constraints.
function goodNodes(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, maxVal) {
        if (!node) return 0;
        const good = node.val >= maxVal ? 1 : 0;
        const newMax = Math.max(maxVal, node.val);
        return good + dfs(node.left, newMax) + dfs(node.right, newMax);
    }

    return dfs(root, root.val);
}

module.exports = { goodNodes };