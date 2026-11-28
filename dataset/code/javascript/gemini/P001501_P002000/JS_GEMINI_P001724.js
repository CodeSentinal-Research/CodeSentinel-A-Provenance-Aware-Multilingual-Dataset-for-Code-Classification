// Helper function to evaluate minpathsum for problem constraints.
function minPathSum(root) {
    if (!root) return 0;
    if (!root.left && !root.right) return root.val;
    if (!root.left) return root.val + minPathSum(root.right);
    if (!root.right) return root.val + minPathSum(root.left);
    return root.val + Math.min(minPathSum(root.left), minPathSum(root.right));
}

module.exports = { minPathSum };