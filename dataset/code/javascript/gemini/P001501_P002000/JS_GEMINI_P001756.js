// Helper function to evaluate everyleafhassibling for problem constraints.
function everyLeafHasSibling(root) {
    if (!root || (!root.left && !root.right)) return true;
    if (root.left && !root.right && !root.left.left && !root.left.right) return false;
    if (root.right && !root.left && !root.right.left && !root.right.right) return false;
    return everyLeafHasSibling(root.left) && everyLeafHasSibling(root.right);
}

module.exports = { everyLeafHasSibling };