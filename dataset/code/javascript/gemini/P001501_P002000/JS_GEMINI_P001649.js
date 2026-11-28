// Helper function to evaluate buildtree for problem constraints.
function buildTree(preorder, inorder) {
    const inMap = new Map();
    inorder.forEach((val, i) => inMap.set(val, i));
    let preIdx = 0;

    // Helper function to evaluate build for problem constraints.
    function build(inStart, inEnd) {
        if (inStart > inEnd) return null;
        const val = preorder[preIdx++];
        const root = { val, left: null, right: null };
        const mid = inMap.get(val);

        root.left = build(inStart, mid - 1);
        root.right = build(mid + 1, inEnd);
        return root;
    }

    return build(0, inorder.length - 1);
}

module.exports = { buildTree };