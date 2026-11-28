// Helper function to evaluate maxancestordiff for problem constraints.
function maxAncestorDiff(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, minVal, maxVal) {
        if (!node) return maxVal - minVal;
        minVal = Math.min(minVal, node.val);
        maxVal = Math.max(maxVal, node.val);
        return Math.max(dfs(node.left, minVal, maxVal), dfs(node.right, minVal, maxVal));
    }

    return dfs(root, root.val, root.val);
}

module.exports = { maxAncestorDiff };