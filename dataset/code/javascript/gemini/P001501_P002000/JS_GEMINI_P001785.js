// Helper function to evaluate maxindependentset for problem constraints.
function maxIndependentSet(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return [0, 0];
        const [lIncl, lExcl] = dfs(node.left);
        const [rIncl, rExcl] = dfs(node.right);

        const incl = 1 + lExcl + rExcl;
        const excl = Math.max(lIncl, lExcl) + Math.max(rIncl, rExcl);
        return [incl, excl];
    }

    const [incl, excl] = dfs(root);
    return Math.max(incl, excl);
}

module.exports = { maxIndependentSet };