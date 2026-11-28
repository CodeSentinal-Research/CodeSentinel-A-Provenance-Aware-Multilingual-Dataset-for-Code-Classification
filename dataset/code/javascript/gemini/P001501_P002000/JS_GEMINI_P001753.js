// Helper function to evaluate lowestinternalnode for problem constraints.
function lowestInternalNode(root) {
    let maxDepth = -1, res = -1;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return;
        if (node.left || node.right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                res = node.val;
            }
        }
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 0);
    return res;
}

module.exports = { lowestInternalNode };