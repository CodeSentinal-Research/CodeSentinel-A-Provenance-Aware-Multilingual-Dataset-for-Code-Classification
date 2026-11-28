// Helper function to evaluate converttothreaded for problem constraints.
function convertToThreaded(root) {
    let prev = null;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        if (prev && !prev.right) {
            prev.right = node;
            prev.isThreaded = true;
        }
        prev = node;
        inorder(node.right);
    }

    inorder(root);
    return root;
}

module.exports = { convertToThreaded };