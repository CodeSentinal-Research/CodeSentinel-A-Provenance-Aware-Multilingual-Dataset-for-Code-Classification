// Helper function to evaluate countleaves for problem constraints.
function countLeaves(root) {
    if (!root) return 0;
    if (!root.left && !root.right) return 1;
    return countLeaves(root.left) + countLeaves(root.right);
}

module.exports = { countLeaves };