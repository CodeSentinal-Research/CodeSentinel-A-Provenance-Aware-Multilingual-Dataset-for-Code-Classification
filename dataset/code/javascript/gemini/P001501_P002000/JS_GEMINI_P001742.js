// Helper function to evaluate getleavesrighttoleft for problem constraints.
function getLeavesRightToLeft(root) {
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return;
        if (!node.left && !node.right) {
            res.push(node.val);
            return;
        }
        dfs(node.right);
        dfs(node.left);
    }

    dfs(root);
    return res;
}

module.exports = { getLeavesRightToLeft };