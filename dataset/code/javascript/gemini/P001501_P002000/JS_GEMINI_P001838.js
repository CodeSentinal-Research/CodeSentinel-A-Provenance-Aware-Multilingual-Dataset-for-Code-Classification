// Helper function to evaluate findtarget for problem constraints.
function findTarget(root, k) {
    const seen = new Set();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return false;
        if (seen.has(k - node.val)) return true;
        seen.add(node.val);
        return dfs(node.left) || dfs(node.right);
    }

    return dfs(root);
}

module.exports = { findTarget };