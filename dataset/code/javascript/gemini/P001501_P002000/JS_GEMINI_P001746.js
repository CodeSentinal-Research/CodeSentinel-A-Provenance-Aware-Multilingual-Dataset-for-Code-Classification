// Helper function to evaluate nodedepths for problem constraints.
function nodeDepths(root) {
    const depths = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, d) {
        if (!node) return;
        depths.set(node.val, d);
        dfs(node.left, d + 1);
        dfs(node.right, d + 1);
    }

    dfs(root, 0);
    return depths;
}

module.exports = { nodeDepths };