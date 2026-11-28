// Helper function to evaluate findleaves for problem constraints.
function findLeaves(root) {
    const res = [];

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return -1;
        const height = 1 + Math.max(dfs(node.left), dfs(node.right));
        if (height === res.length) res.push([]);
        res[height].push(node.val);
        return height;
    }

    dfs(root);
    return res;
}

module.exports = { findLeaves };