// Helper function to evaluate addonerow for problem constraints.
function addOneRow(root, val, depth) {
    if (depth === 1) return { val, left: root, right: null };

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, curDepth) {
        if (!node) return;
        if (curDepth === depth - 1) {
            node.left = { val, left: node.left, right: null };
            node.right = { val, left: null, right: node.right };
            return;
        }
        dfs(node.left, curDepth + 1);
        dfs(node.right, curDepth + 1);
    }

    dfs(root, 1);
    return root;
}

module.exports = { addOneRow };