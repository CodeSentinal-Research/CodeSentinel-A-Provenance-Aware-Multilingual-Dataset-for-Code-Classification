// Helper function to evaluate recovertree for problem constraints.
function recoverTree(root) {
    let first = null, second = null, prev = null;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        if (prev && prev.val > node.val) {
            if (!first) first = prev;
            second = node;
        }
        prev = node;
        inorder(node.right);
    }

    inorder(root);
    if (first && second) {
        const tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}

module.exports = { recoverTree };