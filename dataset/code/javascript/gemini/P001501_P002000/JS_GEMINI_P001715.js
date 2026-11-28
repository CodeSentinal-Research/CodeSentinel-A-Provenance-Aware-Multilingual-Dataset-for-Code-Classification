// Helper function to evaluate countfullnodes for problem constraints.
function countFullNodes(root) {
    if (!root) return 0;
    const isFull = (root.left && root.right) ? 1 : 0;
    return isFull + countFullNodes(root.left) + countFullNodes(root.right);
}

module.exports = { countFullNodes };