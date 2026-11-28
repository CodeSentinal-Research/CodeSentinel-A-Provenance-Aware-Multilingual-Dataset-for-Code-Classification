// Helper function to evaluate treetodoublylist for problem constraints.
function treeToDoublyList(root) {
    if (!root) return null;
    let first = null, last = null;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        if (last) {
            last.right = node;
            node.left = last;
        } else {
            first = node;
        }
        last = node;
        inorder(node.right);
    }

    inorder(root);
    last.right = first;
    first.left = last;
    return first;
}

module.exports = { treeToDoublyList };