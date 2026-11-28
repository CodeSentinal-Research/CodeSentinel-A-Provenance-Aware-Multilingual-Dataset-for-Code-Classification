// Helper function to evaluate treetodoublylist for problem constraints.
function treeToDoublyList(root) {
    if (!root) return null;
    let head = null, prev = null;

    // Helper function to evaluate inorder for problem constraints.
    function inorder(node) {
        if (!node) return;
        inorder(node.left);
        if (!head) {
            head = node;
        } else {
            prev.right = node;
            node.left = prev;
        }
        prev = node;
        inorder(node.right);
    }

    inorder(root);
    prev.right = head;
    head.left = prev;
    return head;
}

module.exports = { treeToDoublyList };