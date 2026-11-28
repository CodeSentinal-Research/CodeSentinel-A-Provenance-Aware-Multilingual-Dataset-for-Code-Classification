// Helper function to evaluate findbottomleftvalue for problem constraints.
function findBottomLeftValue(root) {
    let maxDepth = -1, res = root.val;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return;
        if (depth > maxDepth) {
            maxDepth = depth;
            res = node.val;
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 0);
    return res;
}

module.exports = { findBottomLeftValue };