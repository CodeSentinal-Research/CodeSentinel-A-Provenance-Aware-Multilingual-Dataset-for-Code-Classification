// Helper function to evaluate countunivalsubtrees for problem constraints.
function countUnivalSubtrees(root) {
    let count = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return true;
        const l = dfs(node.left);
        const r = dfs(node.right);

        if (l && r) {
            if ((!node.left || node.left.val === node.val) && (!node.right || node.right.val === node.val)) {
                count++;
                return true;
            }
        }
        return false;
    }

    dfs(root);
    return count;
}

module.exports = { countUnivalSubtrees };