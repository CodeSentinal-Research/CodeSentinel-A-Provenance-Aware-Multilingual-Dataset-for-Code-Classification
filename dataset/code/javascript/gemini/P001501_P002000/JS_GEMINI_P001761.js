// Helper function to evaluate maxsubtreesum for problem constraints.
function maxSubtreeSum(root) {
    let maxSum = -Infinity;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const curSum = node.val + dfs(node.left) + dfs(node.right);
        if (curSum > maxSum) maxSum = curSum;
        return curSum;
    }

    dfs(root);
    return maxSum;
}

module.exports = { maxSubtreeSum };