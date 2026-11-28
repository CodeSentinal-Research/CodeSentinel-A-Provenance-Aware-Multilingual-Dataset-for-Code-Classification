// Helper function to evaluate everyinternalnodeonechild for problem constraints.
function everyInternalNodeOneChild(root) {
    if (!root || (!root.left && !root.right)) return true;
    if (root.left && root.right) return false;
    return everyInternalNodeOneChild(root.left ? root.left : root.right);
}

module.exports = { everyInternalNodeOneChild };