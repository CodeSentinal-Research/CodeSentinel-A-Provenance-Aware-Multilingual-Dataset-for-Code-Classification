// Helper function to evaluate rob for problem constraints.
function rob(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [0, 0];
        const [lRob, lSkip] = dfs(node.left);
        const [rRob, rSkip] = dfs(node.right);

        const robCur = node.val + lSkip + rSkip;
        const skipCur = Math.max(lRob, lSkip) + Math.max(rRob, rSkip);
        return [robCur, skipCur];
    }

    const res = dfs(root);
    return Math.max(res[0], res[1]);
}

module.exports = { rob };