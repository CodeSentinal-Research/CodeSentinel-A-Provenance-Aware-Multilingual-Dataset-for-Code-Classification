// Helper function to evaluate allpathssamelength for problem constraints.
function allPathsSameLength(root) {
    if (!root) return true;
    let leafDepth = null;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return true;
        if (!node.left && !node.right) {
            if (leafDepth === null) {
                leafDepth = depth;
                return true;
            }
            return leafDepth === depth;
        }
        return dfs(node.left, depth + 1) && dfs(node.right, depth + 1);
    }

    return dfs(root, 0);
}

module.exports = { allPathsSameLength };