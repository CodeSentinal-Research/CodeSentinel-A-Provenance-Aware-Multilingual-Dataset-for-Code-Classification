// Helper function to evaluate bsttocumulative for problem constraints.
function bstToCumulative(root) {
    let curSum = 0;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        curSum += node.val;
        node.val = curSum;
        inorder(node.right);
    }

    inorder(root);
    return root;
}

module.exports = { bstToCumulative };