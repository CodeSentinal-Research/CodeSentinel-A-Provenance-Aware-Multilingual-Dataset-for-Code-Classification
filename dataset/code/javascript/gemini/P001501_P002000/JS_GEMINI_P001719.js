// Helper function to evaluate longestpath for problem constraints.
function longestPath(root) {
    let longest = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, path) {
        if (!node) return;
        path.push(node.val);
        if (!node.left && !node.right) {
            if (path.length > longest.length) {
                longest = [...path];
            }
        } else {
            dfs(node.left, path);
            dfs(node.right, path);
        }
        path.pop();
    }

    dfs(root, []);
    return longest;
}

module.exports = { longestPath };