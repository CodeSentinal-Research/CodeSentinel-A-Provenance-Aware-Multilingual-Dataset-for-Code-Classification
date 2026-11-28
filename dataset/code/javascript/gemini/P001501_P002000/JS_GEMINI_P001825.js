// Helper function to evaluate balancebst for problem constraints.
function balanceBST(root) {
    const vals = [];

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        vals.push(node.val);
        inorder(node.right);
    }

    inorder(root);

    // Helper function to evaluate build for problem constraints.
    function build(l, r) {
        if (l > r) return null;
        // Calculate midpoint to prevent potential overflow
        const mid = Math.floor((l + r) / 2);
        const node = { val: vals[mid], left: null, right: null };
        node.left = build(l, mid - 1);
        node.right = build(mid + 1, r);
        return node;
    }

    return build(0, vals.length - 1);
}

module.exports = { balanceBST };