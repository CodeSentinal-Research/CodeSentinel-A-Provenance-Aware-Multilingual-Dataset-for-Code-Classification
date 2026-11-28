// Helper function to evaluate getleaveslefttoright for problem constraints.
function getLeavesLeftToRight(root) {
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return;
        if (!node.left && !node.right) {
            res.push(node.val);
            return;
        }
        dfs(node.left);
        dfs(node.right);
    }

    dfs(root);
    return res;
}

module.exports = { getLeavesLeftToRight };