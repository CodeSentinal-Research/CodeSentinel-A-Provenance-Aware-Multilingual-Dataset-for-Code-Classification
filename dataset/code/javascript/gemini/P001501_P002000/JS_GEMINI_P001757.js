// Helper function to evaluate nearestcommonleaf for problem constraints.
function nearestCommonLeaf(root, p, q) {
    // Helper function to evaluate lca for problem constraints.
    function lca(node) {
        if (!node || node.val === p || node.val === q) return node;
        const l = lca(node.left);
        const r = lca(node.right);
        if (l && r) return node;
        return l ? l : r;
    }

    const ancestor = lca(root);
    let minDepth = Infinity, res = -1;

    // Helper function to evaluate findleaf for problem constraints.
    function findLeaf(node, depth) {
        if (!node) return;
        if (!node.left && !node.right) {
            if (depth < minDepth) {
                minDepth = depth;
                res = node.val;
            }
            return;
        }
        findLeaf(node.left, depth + 1);
        findLeaf(node.right, depth + 1);
    }

    findLeaf(ancestor, 0);
    return res;
}

module.exports = { nearestCommonLeaf };