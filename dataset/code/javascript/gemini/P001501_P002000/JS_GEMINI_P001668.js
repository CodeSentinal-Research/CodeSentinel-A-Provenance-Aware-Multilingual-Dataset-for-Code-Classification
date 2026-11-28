// Helper function to evaluate subtreewithalldeepest for problem constraints.
function subtreeWithAllDeepest(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [0, null];
        const [lDepth, lNode] = dfs(node.left);
        const [rDepth, rNode] = dfs(node.right);
        if (lDepth === rDepth) {
            return [lDepth + 1, node];
        } else if (lDepth > rDepth) {
            return [lDepth + 1, lNode];
        } else {
            return [rDepth + 1, rNode];
        }
    }

    return dfs(root)[1];
}

module.exports = { subtreeWithAllDeepest };