// Helper function to evaluate longestunivaluepath for problem constraints.
function longestUnivaluePath(root) {
    let maxPath = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return 0;
        const lLen = dfs(node.left);
        const rLen = dfs(node.right);

        const lArrow = (node.left && node.left.val === node.val) ? lLen + 1 : 0;
        const rArrow = (node.right && node.right.val === node.val) ? rLen + 1 : 0;

        if (lArrow + rArrow > maxPath) maxPath = lArrow + rArrow;
        return Math.max(lArrow, rArrow);
    }

    dfs(root);
    return maxPath;
}

module.exports = { longestUnivaluePath };