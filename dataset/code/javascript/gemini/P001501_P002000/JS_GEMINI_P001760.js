// Helper function to evaluate converttodescendantsum for problem constraints.
function convertToDescendantSum(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const lSum = dfs(node.left);
        const rSum = dfs(node.right);
        const oldVal = node.val;
        node.val = lSum + rSum;
        return node.val + oldVal;
    }

    dfs(root);
    return root;
}

module.exports = { convertToDescendantSum };