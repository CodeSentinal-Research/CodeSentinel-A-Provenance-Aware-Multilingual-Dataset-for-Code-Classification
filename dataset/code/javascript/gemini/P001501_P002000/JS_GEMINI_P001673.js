// Helper function to evaluate leftsideview for problem constraints.
function leftSideView(root) {
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return;
        if (depth === res.length) res.push(node.val);
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 0);
    return res;
}

module.exports = { leftSideView };