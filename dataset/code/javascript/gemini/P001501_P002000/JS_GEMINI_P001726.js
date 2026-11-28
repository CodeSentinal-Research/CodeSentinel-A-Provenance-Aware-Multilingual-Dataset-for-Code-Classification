// Helper function to evaluate pathsum for problem constraints.
function pathSum(root, targetSum) {
    const map = new Map();
    map.set(0, 1);

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, curSum) {
        if (!node) return 0;
        curSum += node.val;
        let res = map.get(curSum - targetSum) || 0;
        map.set(curSum, (map.get(curSum) || 0) + 1);
        res += dfs(node.left, curSum) + dfs(node.right, curSum);
        map.set(curSum, map.get(curSum) - 1);
        return res;
    }

    return dfs(root, 0);
}

module.exports = { pathSum };