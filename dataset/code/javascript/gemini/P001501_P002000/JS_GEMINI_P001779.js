// Helper function to evaluate longestincreasingpath for problem constraints.
function longestIncreasingPath(root) {
    if (!root) return 0;
    let maxLen = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parentVal, curLen) {
        if (!node) return;
        if (parentVal === null || node.val > parentVal) {
            curLen++;
        } else {
            curLen = 1;
        }
        if (curLen > maxLen) maxLen = curLen;
        dfs(node.left, node.val, curLen);
        dfs(node.right, node.val, curLen);
    }

    dfs(root, null, 0);
    return maxLen;
}

module.exports = { longestIncreasingPath };