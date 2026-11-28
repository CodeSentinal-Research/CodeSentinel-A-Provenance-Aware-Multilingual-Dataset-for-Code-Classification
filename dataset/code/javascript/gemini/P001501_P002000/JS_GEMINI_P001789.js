// Helper function to evaluate isvalidbst for problem constraints.
function isValidBST(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, low, high) {
        if (!node) return true;
        if (node.val <= low || node.val >= high) return false;
        return dfs(node.left, low, node.val) && dfs(node.right, node.val, high);
    }

    return dfs(root, -Infinity, Infinity);
}

module.exports = { isValidBST };