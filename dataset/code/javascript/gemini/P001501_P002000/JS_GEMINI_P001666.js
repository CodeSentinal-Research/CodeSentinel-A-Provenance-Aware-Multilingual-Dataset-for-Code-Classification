// Helper function to evaluate longestzigzag for problem constraints.
function longestZigZag(root) {
    if (!root) return 0;
    let maxLen = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, isLeft, length) {
        if (!node) return;
        if (length > maxLen) maxLen = length;
        if (isLeft) {
            dfs(node.left, true, 1);
            dfs(node.right, false, length + 1);
        } else {
            dfs(node.left, true, length + 1);
            dfs(node.right, false, 1);
        }
    }

    dfs(root.left, true, 1);
    dfs(root.right, false, 1);
    return maxLen;
}

module.exports = { longestZigZag };