// Performs search to locate target element within the given collection.
function rangeSearch(root, low, high) {
    const res = [];

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        if (node.val > low) inorder(node.left);
        if (node.val >= low && node.val <= high) res.push(node.val);
        if (node.val < high) inorder(node.right);
    }

    inorder(root);
    return res;
}

module.exports = { rangeSearch };