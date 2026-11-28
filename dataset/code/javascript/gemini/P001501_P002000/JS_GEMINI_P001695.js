// Helper function to evaluate sumroottoleaf for problem constraints.
function sumRootToLeaf(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, curVal) {
        if (!node) return 0;
        curVal = (curVal << 1) | node.val;
        if (!node.left && !node.right) return curVal;
        return dfs(node.left, curVal) + dfs(node.right, curVal);
    }

    return dfs(root, 0);
}

module.exports = { sumRootToLeaf };