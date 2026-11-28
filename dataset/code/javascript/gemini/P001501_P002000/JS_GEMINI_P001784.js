// Helper function to evaluate buildtree for problem constraints.
function buildTree(levelOrder, inorder) {
    if (!levelOrder.length || !inorder.length) return null;

    const rootVal = levelOrder[0];
    const root = { val: rootVal, left: null, right: null };
    const idx = inorder.indexOf(rootVal);

    const leftInorder = new Set(inorder.slice(0, idx));
    const rightInorder = new Set(inorder.slice(idx + 1));

    const leftLevel = levelOrder.filter(x => leftInorder.has(x));
    const rightLevel = levelOrder.filter(x => rightInorder.has(x));

    root.left = buildTree(leftLevel, inorder.slice(0, idx));
    root.right = buildTree(rightLevel, inorder.slice(idx + 1));
    return root;
}

module.exports = { buildTree };