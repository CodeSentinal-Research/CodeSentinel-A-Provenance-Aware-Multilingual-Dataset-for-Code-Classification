// Helper function to evaluate countinternalnodes for problem constraints.
function countInternalNodes(root) {
    if (!root || (!root.left && !root.right)) return 0;
    return 1 + countInternalNodes(root.left) + countInternalNodes(root.right);
}

module.exports = { countInternalNodes };