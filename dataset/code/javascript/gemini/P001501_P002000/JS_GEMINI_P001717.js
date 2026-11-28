// Helper function to evaluate countpaths for problem constraints.
function countPaths(root) {
    if (!root) return 0;
    if (!root.left && !root.right) return 1;
    return countPaths(root.left) + countPaths(root.right);
}

module.exports = { countPaths };