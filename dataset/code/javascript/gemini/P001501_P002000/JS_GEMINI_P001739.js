// Helper function to evaluate removeleaves for problem constraints.
function removeLeaves(root) {
    if (!root || (!root.left && !root.right)) return null;
    root.left = removeLeaves(root.left);
    root.right = removeLeaves(root.right);
    return root;
}

module.exports = { removeLeaves };