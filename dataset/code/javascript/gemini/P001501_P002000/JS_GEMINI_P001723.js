// Helper function to evaluate maxpathsum for problem constraints.
function maxPathSum(root) {
    if (!root) return 0;
    if (!root.left && !root.right) return root.val;
    if (!root.left) return root.val + maxPathSum(root.right);
    if (!root.right) return root.val + maxPathSum(root.left);
    return root.val + Math.max(maxPathSum(root.left), maxPathSum(root.right));
}

module.exports = { maxPathSum };