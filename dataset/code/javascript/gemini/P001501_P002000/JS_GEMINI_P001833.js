// Helper function to evaluate countdeadends for problem constraints.
function countDeadEnds(root) {
    let count = 0;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, low, high) {
        if (!node) return;
        if (low === high) {
            count++;
            return;
        }
        dfs(node.left, low, node.val - 1);
        dfs(node.right, node.val + 1, high);
    }

    dfs(root, 1, Infinity);
    return count;
}

module.exports = { countDeadEnds };