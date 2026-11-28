// Helper function to evaluate isfull for problem constraints.
function isFull(root) {
    if (!root) return true;
    if (!root.left && !root.right) return true;
    if (root.left && root.right) {
        return isFull(root.left) && isFull(root.right);
    }
    return false;
}

module.exports = { isFull };