// Helper function to evaluate issiblings for problem constraints.
function isSiblings(root, a, b) {
    if (!root) return false;
    if (root.left && root.right) {
        if ((root.left.val === a && root.right.val === b) || (root.left.val === b && root.right.val === a)) {
            return true;
        }
    }
    return isSiblings(root.left, a, b) || isSiblings(root.right, a, b);
}

module.exports = { isSiblings };