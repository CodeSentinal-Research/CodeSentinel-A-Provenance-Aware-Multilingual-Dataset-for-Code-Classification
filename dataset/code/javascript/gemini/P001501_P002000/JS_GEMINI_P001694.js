// Helper function to evaluate findclosestleaf for problem constraints.
function findClosestLeaf(root, k) {
    const parentMap = new Map();
    let targetNode = null;

    // Helper function to evaluate dfs for problem constraints.
    function dfs(node, parent) {
        if (!node) return;
        if (node.val === k) targetNode = node;
        parentMap.set(node, parent);
        dfs(node.left, node);
        dfs(node.right, node);
    }

    dfs(root, null);

    const visited = new Set([targetNode]);
    const q = [targetNode];

    while (q.length) {
        const curr = q.shift();
        if (!curr.left && !curr.right) return curr.val;

        const neighbors = [curr.left, curr.right, parentMap.get(curr)];
        for (const next of neighbors) {
            if (next && !visited.has(next)) {
                visited.add(next);
                q.push(next);
            }
        }
    }
    return -1;
}

module.exports = { findClosestLeaf };