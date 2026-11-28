// Helper function to evaluate deepestleftleaf for problem constraints.
function deepestLeftLeaf(root) {
    let maxDepth = -1;
    let res = -1;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth, isLeft) {
        if (!node) return;
        if (isLeft && !node.left && !node.right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node.val;
            }
        }
        dfs(node.left, depth + 1, true);
        dfs(node.right, depth + 1, false);
    }

    dfs(root, 0, false);
    return res;
}

module.exports = { deepestLeftLeaf };