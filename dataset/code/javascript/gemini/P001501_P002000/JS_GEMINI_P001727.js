// Helper function to evaluate binarytreepaths for problem constraints.
function binaryTreePaths(root) {
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, path) {
        if (!node) return;
        path += node.val;
        if (!node.left && !node.right) {
            res.push(path);
        } else {
            dfs(node.left, path + '->');
            dfs(node.right, path + '->');
        }
    }

    dfs(root, '');
    return res;
}

module.exports = { binaryTreePaths };