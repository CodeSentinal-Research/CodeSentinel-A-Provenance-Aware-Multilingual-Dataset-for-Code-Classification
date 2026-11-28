// Helper function to evaluate antidiagonaltraversal for problem constraints.
function antiDiagonalTraversal(root) {
    const map = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, d) {
        if (!node) return;
        if (!map.has(d)) map.set(d, []);
        map.get(d).push(node.val);
        dfs(node.right, d + 1);
        dfs(node.left, d);
    }

    dfs(root, 0);
    const sortedKeys = Array.from(map.keys()).sort((a, b) => a - b);
    const res = [];
    for (const k of sortedKeys) {
        res.push(...map.get(k));
    }
    return res;
}

module.exports = { antiDiagonalTraversal };