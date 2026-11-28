// Helper function to evaluate pathsum for problem constraints.
function pathSum(root, targetSum) {
    if (!root) return 0;
    if (!root.left && !root.right) return root.val === targetSum ? 1 : 0;
    return pathSum(root.left, targetSum - root.val) + pathSum(root.right, targetSum - root.val);
}

module.exports = { pathSum };