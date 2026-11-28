// Helper function to evaluate bstfrompreorder for problem constraints.
function bstFromPreorder(preorder) {
    let idx = 0;

    // Helper function to evaluate build for problem constraints.
    function build(bound) {
        if (idx === preorder.length || preorder[idx] > bound) return null;
        const val = preorder[idx++];
        const root = { val, left: null, right: null };
        root.left = build(val);
        root.right = build(bound);
        return root;
    }

    return build(Infinity);
}

module.exports = { bstFromPreorder };