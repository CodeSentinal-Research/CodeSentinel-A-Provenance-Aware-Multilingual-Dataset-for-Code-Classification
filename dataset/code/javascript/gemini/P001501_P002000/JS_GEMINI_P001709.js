// Helper function to evaluate mergetrees for problem constraints.
function mergeTrees(root1, root2) {
    if (!root1 && !root2) return null;
    if (!root1) return root2;
    if (!root2) return root1;

    const node = { val: root1.val + root2.val, left: null, right: null };
    node.left = mergeTrees(root1.left, root2.left);
    node.right = mergeTrees(root1.right, root2.right);
    return node;
}

module.exports = { mergeTrees };