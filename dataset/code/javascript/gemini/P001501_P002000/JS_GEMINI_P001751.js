// Helper function to evaluate countnodeswithkdescendants for problem constraints.
function countNodesWithKDescendants(root, k) {
    let ans = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const desc = dfs(node.left) + dfs(node.right);
        if (desc === k) ans++;
        return desc + 1;
    }

    dfs(root);
    return ans;
}

module.exports = { countNodesWithKDescendants };