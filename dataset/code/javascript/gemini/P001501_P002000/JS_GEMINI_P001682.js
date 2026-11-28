// Helper function to evaluate checkleavessamelevel for problem constraints.
function checkLeavesSameLevel(root) {
    let leafLevel = null;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, level) {
        if (!node) return true;
        if (!node.left && !node.right) {
            if (leafLevel === null) {
                leafLevel = level;
                return true;
            }
            return leafLevel === level;
        }
        return dfs(node.left, level + 1) && dfs(node.right, level + 1);
    }

    return dfs(root, 0);
}

module.exports = { checkLeavesSameLevel };