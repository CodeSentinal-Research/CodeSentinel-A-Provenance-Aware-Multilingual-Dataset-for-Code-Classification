// Helper function to evaluate inverttree for problem constraints.
function invertTree(root) {
    if (!root) return null;
    const left = invertTree(root.left);
    const right = invertTree(root.right);
    root.left = right;
    root.right = left;
    return root;
}

module.exports = { invertTree };