// Helper function to evaluate lowestleaf for problem constraints.
function lowestLeaf(root) {
    let minDepth = Infinity;
    let res = -1;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return;
        if (!node.left && !node.right) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node.val;
            }
            return;
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 1);
    return res;
}

module.exports = { lowestLeaf };