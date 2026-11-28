// Helper function to evaluate findmode for problem constraints.
function findMode(root) {
    const count = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node) {
        if (!node) return;
        count.set(node.val, (count.get(node.val) || 0) + 1);
        dfs(node.left);
        dfs(node.right);
    }

    dfs(root);
    let maxF = 0;
    for (const v of count.values()) {
        if (v > maxF) maxF = v;
    }

    const res = [];
    for (const [k, v] of count.entries()) {
        if (v === maxF) res.push(k);
    }
    return res;
}

module.exports = { findMode };