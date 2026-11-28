// Helper function to evaluate isdeadend for problem constraints.
function isDeadEnd(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, low, high) {
        if (!node) return false;
        if (low === high) return true;
        return dfs(node.left, low, node.val - 1) || dfs(node.right, node.val + 1, high);
    }

    return dfs(root, 1, Infinity);
}

module.exports = { isDeadEnd };