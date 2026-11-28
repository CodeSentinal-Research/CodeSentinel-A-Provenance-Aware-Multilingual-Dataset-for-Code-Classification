// Helper function to evaluate canbebstbyrotations for problem constraints.
function canBeBSTByRotations(root) {
    let prev = -Infinity;
    let possible = true;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node || !possible) return;
        inorder(node.left);
        if (node.val <= prev) {
            possible = false;
            return;
        }
        prev = node.val;
        inorder(node.right);
    }

    inorder(root);
    return possible;
}

module.exports = { canBeBSTByRotations };