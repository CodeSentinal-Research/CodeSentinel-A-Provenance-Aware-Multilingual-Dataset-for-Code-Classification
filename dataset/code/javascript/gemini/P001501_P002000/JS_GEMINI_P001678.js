// Helper function to evaluate iscousins for problem constraints.
function isCousins(root, x, y) {
    let xParent = null, yParent = null;
    let xDepth = -1, yDepth = -1;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parent, depth) {
        if (!node) return;
        if (node.val === x) {
            xParent = parent;
            xDepth = depth;
        } else if (node.val === y) {
            yParent = parent;
            yDepth = depth;
        }
        dfs(node.left, node, depth + 1);
        dfs(node.right, node, depth + 1);
    }

    dfs(root, null, 0);
    return xDepth === yDepth && xParent !== yParent;
}

module.exports = { isCousins };