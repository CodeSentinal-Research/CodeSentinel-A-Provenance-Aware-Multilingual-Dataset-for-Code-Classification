// Helper function to evaluate isstrictbinarytree for problem constraints.
function isStrictBinaryTree(root) {
    if (!root) return true;
    if (!root.left && !root.right) return true;
    if (root.left && root.right) {
        return isStrictBinaryTree(root.left) && isStrictBinaryTree(root.right);
    }
    return false;
}

module.exports = { isStrictBinaryTree };