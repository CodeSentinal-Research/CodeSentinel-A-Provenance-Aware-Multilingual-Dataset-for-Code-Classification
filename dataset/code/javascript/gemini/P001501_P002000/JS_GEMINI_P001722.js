// Helper function to evaluate sumevenlevels for problem constraints.
function sumEvenLevels(root) {
    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, level) {
        if (!node) return 0;
        const cur = level % 2 === 0 ? node.val : 0;
        return cur + dfs(node.left, level + 1) + dfs(node.right, level + 1);
    }

    return dfs(root, 1);
}

module.exports = { sumEvenLevels };