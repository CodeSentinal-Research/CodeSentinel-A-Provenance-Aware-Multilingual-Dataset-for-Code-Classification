// Helper function to evaluate counthalfnodes for problem constraints.
function countHalfNodes(root) {
    if (!root) return 0;
    const isHalf = ((root.left && !root.right) || (!root.left && root.right)) ? 1 : 0;
    return isHalf + countHalfNodes(root.left) + countHalfNodes(root.right);
}

module.exports = { countHalfNodes };