// Helper function to evaluate prunetree for problem constraints.
function pruneTree(root) {
    if (!root) return null;
    root.left = pruneTree(root.left);
    root.right = pruneTree(root.right);
    if (!root.left && !root.right && root.val === 0) return null;
    return root;
}

module.exports = { pruneTree };