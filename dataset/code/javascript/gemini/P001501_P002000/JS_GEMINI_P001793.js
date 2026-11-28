// Helper function to evaluate inorderpredecessor for problem constraints.
function inorderPredecessor(root, p) {
    let pred = null;
    let cur = root;
    while (cur) {
        if (cur.val < p.val) {
            pred = cur;
            cur = cur.right;
        } else {
            cur = cur.left;
        }
    }
    return pred;
}

module.exports = { inorderPredecessor };