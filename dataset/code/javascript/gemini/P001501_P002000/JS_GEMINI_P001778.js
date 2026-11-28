// Helper function to evaluate countmonotonicpaths for problem constraints.
function countMonotonicPaths(root) {
    if (!root) return 0;
    let count = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parentVal, isInc, isDec) {
        if (!node) return;
        if (parentVal !== null) {
            if (node.val < parentVal) isInc = false;
            if (node.val > parentVal) isDec = false;
        }
        if (!node.left && !node.right) {
            if (isInc || isDec) count++;
            return;
        }
        dfs(node.left, node.val, isInc, isDec);
        dfs(node.right, node.val, isInc, isDec);
    }

    dfs(root, null, true, true);
    return count;
}

module.exports = { countMonotonicPaths };