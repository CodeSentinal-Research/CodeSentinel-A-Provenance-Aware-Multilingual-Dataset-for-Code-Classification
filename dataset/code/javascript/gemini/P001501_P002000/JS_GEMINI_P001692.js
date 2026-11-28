// Helper function to evaluate longestconsecutive for problem constraints.
function longestConsecutive(root) {
    if (!root) return 0;
    let maxLen = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parent, length) {
        if (!node) return;
        if (parent && node.val === parent.val + 1) {
            length++;
        } else {
            length = 1;
        }
        if (length > maxLen) maxLen = length;
        dfs(node.left, node, length);
        dfs(node.right, node, length);
    }

    dfs(root, null, 0);
    return maxLen;
}

module.exports = { longestConsecutive };