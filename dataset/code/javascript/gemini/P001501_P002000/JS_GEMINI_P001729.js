// Helper function to evaluate finddistance for problem constraints.
function findDistance(root, p, q) {
    if (p === q) return 0;

    // Helper function to evaluate lca for problem constraints.
    function lca(node) {
        if (!node || node.val === p || node.val === q) return node;
        const l = lca(node.left);
        const r = lca(node.right);
        if (l && r) return node;
        return l ? l : r;
    }

    // Helper function to evaluate dist for problem constraints.
    function dist(node, target) {
        if (!node) return -1;
        if (node.val === target) return 0;
        let d = dist(node.left, target);
        if (d >= 0) return d + 1;
        d = dist(node.right, target);
        if (d >= 0) return d + 1;
        return -1;
    }

    const ancestor = lca(root);
    return dist(ancestor, p) + dist(ancestor, q);
}

module.exports = { findDistance };