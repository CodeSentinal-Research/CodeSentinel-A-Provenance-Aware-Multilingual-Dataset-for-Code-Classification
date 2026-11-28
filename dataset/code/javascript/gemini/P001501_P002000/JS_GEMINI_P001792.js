// Helper function to evaluate inordersuccessor for problem constraints.
function inorderSuccessor(root, p) {
    let succ = null;
    let cur = root;
    while (cur) {
        if (cur.val > p.val) {
            succ = cur;
            cur = cur.left;
        } else {
            cur = cur.right;
        }
    }
    return succ;
}

module.exports = { inorderSuccessor };