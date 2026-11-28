// Helper function to evaluate countancestors for problem constraints.
function countAncestors(root) {
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, depth) {
        if (!node) return;
        map.set(node.val, depth);
        dfs(node.left, depth + 1);
        dfs(node.right, depth + 1);
    }

    dfs(root, 0);
    return map;
}

module.exports = { countAncestors };