// Helper function to evaluate containsduplicate for problem constraints.
function containsDuplicate(root) {
    const seen = new Set();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return false;
        if (seen.has(node.val)) return true;
        seen.add(node.val);
        return dfs(node.left) || dfs(node.right);
    }

    return dfs(root);
}

module.exports = { containsDuplicate };