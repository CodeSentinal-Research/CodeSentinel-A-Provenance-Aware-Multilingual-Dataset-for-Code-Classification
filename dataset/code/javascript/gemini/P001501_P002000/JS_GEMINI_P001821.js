// Helper function to evaluate converttominheap for problem constraints.
function convertToMinHeap(root) {
    const vals = [];

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        vals.push(node.val);
        inorder(node.right);
    }

    inorder(root);
    let idx = 0;

    // Helper function to evaluate preorder for problem constraints.
    function preorder(node) {
        if (!node) return;
        node.val = vals[idx++];
        preorder(node.left);
        preorder(node.right);
    }

    preorder(root);
    return root;
}

module.exports = { convertToMinHeap };