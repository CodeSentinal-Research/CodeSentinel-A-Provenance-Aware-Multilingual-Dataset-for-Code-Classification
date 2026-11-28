// Helper function to evaluate nodeheights for problem constraints.
function nodeHeights(root) {
    const heights = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return -1;
        const h = 1 + Math.max(dfs(node.left), dfs(node.right));
        heights.set(node.val, h);
        return h;
    }

    dfs(root);
    return heights;
}

module.exports = { nodeHeights };