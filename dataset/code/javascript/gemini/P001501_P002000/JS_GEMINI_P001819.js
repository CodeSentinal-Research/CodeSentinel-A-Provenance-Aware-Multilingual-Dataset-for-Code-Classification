// Helper function to evaluate rankofkey for problem constraints.
function rankOfKey(root, key) {
    let rank = 0;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return false;
        if (inorder(node.left)) return true;
        if (node.val === key) {
            rank++;
            return true;
        }
        if (node.val < key) rank++;
        return inorder(node.right);
    }

    const found = inorder(root);
    return found ? rank : -1;
}

module.exports = { rankOfKey };