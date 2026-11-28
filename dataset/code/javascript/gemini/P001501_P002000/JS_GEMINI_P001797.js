// Helper function to evaluate bstfrompostorder for problem constraints.
function bstFromPostorder(postorder) {
    let idx = postorder.length - 1;

    // Helper function to evaluate build for problem constraints.
    function build(bound) {
        if (idx < 0 || postorder[idx] < bound) return null;
        const val = postorder[idx--];
        const root = { val, left: null, right: null };
        root.right = build(val);
        root.left = build(bound);
        return root;
    }

    return build(-Infinity);
}

module.exports = { bstFromPostorder };