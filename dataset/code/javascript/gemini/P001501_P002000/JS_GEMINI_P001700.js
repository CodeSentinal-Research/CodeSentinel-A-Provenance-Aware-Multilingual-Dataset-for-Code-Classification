// Helper function to evaluate reverseoddlevels for problem constraints.
function reverseOddLevels(root) {
    if (!root) return null;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(left, right, level) {
        if (!left || !right) return;
        if (level % 2 === 1) {
            const tmp = left.val;
            left.val = right.val;
            right.val = tmp;
        }
        dfs(left.left, right.right, level + 1);
        dfs(left.right, right.left, level + 1);
    }

    dfs(root.left, root.right, 1);
    return root;
}

module.exports = { reverseOddLevels };