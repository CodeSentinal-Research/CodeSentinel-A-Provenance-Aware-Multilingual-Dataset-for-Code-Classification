// Helper function to evaluate longestalternatingpath for problem constraints.
function longestAlternatingPath(root) {
    if (!root) return 0;
    let maxLen = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parentVal, curLen) {
        if (!node) return;
        if (parentVal !== null && (Math.abs(node.val % 2) !== Math.abs(parentVal % 2))) {
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

module.exports = { longestAlternatingPath };