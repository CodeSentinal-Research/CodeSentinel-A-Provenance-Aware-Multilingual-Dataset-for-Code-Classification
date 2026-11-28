// Helper function to evaluate smallestfromleaf for problem constraints.
function smallestFromLeaf(root) {
    let ans = '~';

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, path) {
        if (!node) return;
        path = String.fromCharCode(97 + node.val) + path;
        if (!node.left && !node.right) {
            if (path < ans) ans = path;
        }
        dfs(node.left, path);
        dfs(node.right, path);
    }

    dfs(root, '');
    return ans;
}

module.exports = { smallestFromLeaf };