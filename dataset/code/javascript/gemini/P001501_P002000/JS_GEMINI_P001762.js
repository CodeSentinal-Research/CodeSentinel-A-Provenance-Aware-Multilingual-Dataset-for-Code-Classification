// Helper function to evaluate minsubtreesum for problem constraints.
function minSubtreeSum(root) {
    let minSum = Infinity;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const curSum = node.val + dfs(node.left) + dfs(node.right);
        if (curSum < minSum) minSum = curSum;
        return curSum;
    }

    dfs(root);
    return minSum;
}

module.exports = { minSubtreeSum };