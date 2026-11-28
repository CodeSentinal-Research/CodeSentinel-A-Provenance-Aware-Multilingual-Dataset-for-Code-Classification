// Helper function to evaluate smallestinsertionseq for problem constraints.
function smallestInsertionSeq(root) {
    const res = [];

    // Helper function to evaluate preorder for problem constraints.
    function preorder(node) {
        if (!node) return;
        res.push(node.val);
        preorder(node.left);
        preorder(node.right);
    }

    preorder(root);
    return res;
}

module.exports = { smallestInsertionSeq };