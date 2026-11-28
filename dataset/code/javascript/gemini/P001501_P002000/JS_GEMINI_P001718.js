// Helper function to evaluate countpathskedges for problem constraints.
function countPathsKEdges(root, k) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, edges) {
        if (!node) return 0;
        if (!node.left && !node.right) return edges === k ? 1 : 0;
        return dfs(node.left, edges + 1) + dfs(node.right, edges + 1);
    }

    return dfs(root, 0);
}

module.exports = { countPathsKEdges };