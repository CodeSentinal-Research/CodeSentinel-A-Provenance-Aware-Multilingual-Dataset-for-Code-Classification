// Helper function to evaluate joinbst for problem constraints.
function joinBST(root1, root2) {
    if (!root1) return root2;
    if (!root2) return root1;

    // Helper function to evaluate insert for problem constraints.
    function insert(node, val) {
        if (!node) return { val, left: null, right: null };
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }

    // Helper function to evaluate addall for problem constraints.
    function addAll(node) {
        if (!node) return;
        insert(root1, node.val);
        addAll(node.left);
        addAll(node.right);
    }

    addAll(root2);
    return root1;
}

module.exports = { joinBST };