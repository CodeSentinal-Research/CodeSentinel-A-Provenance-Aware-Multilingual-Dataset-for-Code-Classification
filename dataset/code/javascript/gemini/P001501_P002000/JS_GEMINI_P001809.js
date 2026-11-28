// Helper function to evaluate bsttogst for problem constraints.
function bstToGst(root) {
    let curSum = 0;

    // Helper function to evaluate reverseinorder for problem constraints.
    function reverseInorder(node) {
        if (!node) return;
        reverseInorder(node.right);
        curSum += node.val;
        node.val = curSum;
        reverseInorder(node.left);
    }

    reverseInorder(root);
    return root;
}

module.exports = { bstToGst };