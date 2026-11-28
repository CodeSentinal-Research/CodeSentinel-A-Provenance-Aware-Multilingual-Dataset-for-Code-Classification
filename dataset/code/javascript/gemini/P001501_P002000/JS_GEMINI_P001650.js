// Helper function to evaluate buildtree for problem constraints.
function buildTree(inorder, postorder) {
    const inMap = new Map();
    inorder.forEach((val, i) => inMap.set(val, i));
    let postIdx = postorder.length - 1;

    // Helper function to evaluate build for problem constraints.
    function build(inStart, inEnd) {
        if (inStart > inEnd) return null;
        const val = postorder[postIdx--];
        const root = { val, left: null, right: null };
        const mid = inMap.get(val);

        root.right = build(mid + 1, inEnd);
        root.left = build(inStart, mid - 1);
        return root;
    }

    return build(0, inorder.length - 1);
}

module.exports = { buildTree };